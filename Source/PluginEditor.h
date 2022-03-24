/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class EQAudioProcessorEditor  : public juce::AudioProcessorEditor//, public juce::Slider::Listener
{
public:
    EQAudioProcessorEditor (EQAudioProcessor&, juce::AudioProcessorValueTreeState& vts);
    ~EQAudioProcessorEditor() override;
   // void sliderValueChanged(juce::Slider* slider) override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;




private:

    juce::AudioProcessorValueTreeState& valueTreeState;

    typedef juce::AudioProcessorValueTreeState::SliderAttachment SliderAttachment;
    typedef juce::AudioProcessorValueTreeState::ButtonAttachment ButtonAttachment;


    /*
    juce::Slider frequencySlider;

    juce::IIRFilter filter;
    */

    std::unique_ptr<SliderAttachment> cutoffAttachment;
    std::unique_ptr<SliderAttachment> resonanceAttachment;

    juce::Slider filterCutoffDial;
    juce::Slider filterResDial;

    juce::ScopedPointer<juce::AudioProcessorValueTreeState::SliderAttachment> filterCutoffValue;
    juce::ScopedPointer<juce::AudioProcessorValueTreeState::SliderAttachment> filterResValue;
    

    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    EQAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (EQAudioProcessorEditor)
};
