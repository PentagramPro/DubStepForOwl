/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
DubStepForOwlAudioProcessorEditor::DubStepForOwlAudioProcessorEditor (DubStepForOwlAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);

    addAndMakeVisible(mGui);
    mGui.Initialize(this, processor.GetStateManager());
    mRegistryListenerHandle = processor.GetPropertiesRegistry().AddListener(*this);
    OnPropertiesFromSynthState();

    for (auto element : mGui.getChildren()) {
        IIndicator* indicator = dynamic_cast<IIndicator*>(element);
        if (indicator) {
            indicator->SetPropertiesRegistry(processor.GetPropertiesRegistry());
        }
    }
}

DubStepForOwlAudioProcessorEditor::~DubStepForOwlAudioProcessorEditor()
{
}

//==============================================================================
void DubStepForOwlAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);
}

void DubStepForOwlAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void DubStepForOwlAudioProcessorEditor::OnPropertiesFromSynthState() {
    for (auto component : mGui.getChildren()) {
        Slider* slider = dynamic_cast<Slider*>(component);
        if (slider && processor.GetPropertiesRegistry().HasProperty(slider->getName().toStdString())) {
            slider->setValue(processor.GetPropertiesRegistry().GetPropertyValueFromReference(slider->getName().toStdString()));
        }
    }
}

void DubStepForOwlAudioProcessorEditor::OnValueChanged(const std::string &name, float value) {
    processor.GetPropertiesRegistry().SetProperty(name, value);
}
