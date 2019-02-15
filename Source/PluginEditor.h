/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "UI/DubStepGuiImpl.h"
#include "VSTComponents/OwlUI/IGuiListener.h"
#include "VSTComponents/Owl/ProperiesRegistry.h"
#include "VSTComponents/Owl/ListenerHandle.h"

//==============================================================================
/**
*/
class DubStepForOwlAudioProcessorEditor  : public AudioProcessorEditor, private IGuiListener, public IPropertiesRegistryListener
{
public:
    DubStepForOwlAudioProcessorEditor (NewProjectAudioProcessor&);
    ~DubStepForOwlAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    void OnPropertiesFromSynthState() override;

    void OnValueChanged(const std::string &name, float value) override;


    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    NewProjectAudioProcessor& processor;
    IListenerHandle mRegistryListenerHandle;

    CDubStepGuiImpl mGui;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DubStepForOwlAudioProcessorEditor)
};
