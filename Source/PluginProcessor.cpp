#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "VSTComponents/Owl/VoiceModuleHost.h"
#include "VSTComponents/Owl/VoiceModuleHostSound.h"
#include "VSTComponents/Owl/SynthState.h"

#include "VSTComponents/OwlVoices/SawtoothVoice.h"

//==============================================================================
NewProjectAudioProcessor::NewProjectAudioProcessor()

     : AudioProcessor (BusesProperties().withOutput ("Output", AudioChannelSet::stereo(), true))
, mStateManager(mPropRegistry)
{
    mHost = new CVoiceModuleHost(mPropRegistry);

    mHost->AddModule(new CSawtoothVoice("test",*mHost,1));

    mSynth.addVoice(mHost);
    mSynth.addSound(new CVoiceModuleHostSound());
}

NewProjectAudioProcessor::~NewProjectAudioProcessor()
{
}

//==============================================================================
const String NewProjectAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool NewProjectAudioProcessor::acceptsMidi() const
{
    return true;
}

bool NewProjectAudioProcessor::producesMidi() const
{
    return false;
}

bool NewProjectAudioProcessor::isMidiEffect() const
{
    return false;
}

double NewProjectAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int NewProjectAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int NewProjectAudioProcessor::getCurrentProgram()
{
    return 0;
}

void NewProjectAudioProcessor::setCurrentProgram (int index)
{
}

const String NewProjectAudioProcessor::getProgramName (int index)
{
    return {};
}

void NewProjectAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void NewProjectAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    mSynth.setCurrentPlaybackSampleRate(sampleRate);
}

void NewProjectAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool NewProjectAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
    return !(layouts.getMainOutputChannelSet() != AudioChannelSet::mono() && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo());

}
#endif

void NewProjectAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    if (mInternalBuffer.getNumSamples() < buffer.getNumSamples()) {
        mInternalBuffer.setSize(3, buffer.getNumSamples());
    }
    mInternalBuffer.clear();
    //buffer.setSize(3, buffer.getNumChannels(), true, false, true);
    mSynth.renderNextBlock(mInternalBuffer, midiMessages, 0, buffer.getNumSamples());
    buffer.copyFrom(0, 0, mInternalBuffer, 0, 0, buffer.getNumSamples());
    buffer.copyFrom(1, 0, mInternalBuffer, 1, 0, buffer.getNumSamples());
}

//==============================================================================
bool NewProjectAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* NewProjectAudioProcessor::createEditor()
{
    return new DubStepForOwlAudioProcessorEditor (*this);
}

//==============================================================================
void NewProjectAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    mStateManager.SaveStateToMemory(destData);
}

void NewProjectAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    mStateManager.LoadStateFromMemory(MemoryBlock(data, sizeInBytes));
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new NewProjectAudioProcessor();
}
