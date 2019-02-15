/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "VSTComponents/Owl/ProperiesRegistry.h"
#include "VSTComponents/Owl/SynthStateManager.h"

class CVoiceModuleHost;

//==============================================================================
/**
*/
class DubStepForOwlAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    DubStepForOwlAudioProcessor();
    ~DubStepForOwlAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    CPropertiesRegistry& GetPropertiesRegistry() { return mPropRegistry; }
    CSynthStateManager& GetStateManager() { return mStateManager; }

private:

    CSynthStateManager mStateManager;
    CPropertiesRegistry mPropRegistry;
    Synthesiser mSynth;
    AudioBuffer<float> mInternalBuffer;

    CVoiceModuleHost* mHost;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DubStepForOwlAudioProcessor)
};
