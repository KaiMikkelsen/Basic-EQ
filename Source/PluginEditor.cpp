/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
EQAudioProcessorEditor::EQAudioProcessorEditor(EQAudioProcessor& p, juce::AudioProcessorValueTreeState& vts)
    : AudioProcessorEditor(&p), audioProcessor(p), valueTreeState(vts)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.

    //frequencySlider.setSliderStyle(juce::Slider::SliderStyle::LinearBarVertical);
    /*
    frequencySlider.setRange(5000, 20000, 10);
    frequencySlider.setValue(10000);
    frequencySlider.addListener(this);
    addAndMakeVisible(frequencySlider);
    
    audioProcessor.frequency = frequencySlider.getValue();
    */

    addAndMakeVisible(filterCutoffDial);
    addAndMakeVisible(filterResDial);

    cutoffAttachment.reset(new SliderAttachment(valueTreeState, "cutoff", filterCutoffDial));
    resonanceAttachment.reset(new SliderAttachment(valueTreeState, "resonance", filterResDial));


    setSize (400, 300);
}

EQAudioProcessorEditor::~EQAudioProcessorEditor()
{
}



//==============================================================================
void EQAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
   // g.drawFittedText ("test!", getLocalBounds(), juce::Justification::centred, 1);
}

void EQAudioProcessorEditor::resized()
{
    //frequencySlider.setBounds(50, 50, 200, 50);

    filterCutoffDial.setBounds(50, 50, 200, 50);
    filterResDial.setBounds(50, 100, 200, 50);
}

/*
void EQAudioProcessorEditor::sliderValueChanged(juce::Slider* slider)
{

    if (slider == &frequencySlider)
    {
        audioProcessor.frequency = frequencySlider.getValue();
        audioProcessor.coefficients = audioProcessor.coefficients.makeLowPass(audioProcessor.getSampleRate(), frequencySlider.getValue());


    }



}
*/