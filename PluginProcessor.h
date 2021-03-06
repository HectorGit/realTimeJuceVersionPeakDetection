/*
==============================================================================

This file was auto-generated!

It contains the basic framework code for a JUCE plugin processor.

==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
//#include "MarsyasProcessor.h"
#include "MarsyasRealtime.h"
#include "OpenNNClassifier.h"
#include "MarsyasPlayerNet.h"

//==============================================================================
/**
*/
class PluginCloneForGuitarAudioProcessor : public AudioProcessor
{
public:
	//==============================================================================
	PluginCloneForGuitarAudioProcessor();
	~PluginCloneForGuitarAudioProcessor();

	//==============================================================================
	void prepareToPlay(double sampleRate, int samplesPerBlock) override;
	void releaseResources() override;

#ifndef JucePlugin_PreferredChannelConfigurations
	bool isBusesLayoutSupported(const BusesLayout& layouts) const override;
#endif

	void processBlock(AudioSampleBuffer&, MidiBuffer&) override;

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
	void setCurrentProgram(int index) override;
	const String getProgramName(int index) override;
	void changeProgramName(int index, const String& newName) override;

	//==============================================================================
	void getStateInformation(MemoryBlock& destData) override;
	void setStateInformation(const void* data, int sizeInBytes) override;
	//==============================================================================
	//ScopedPointer<MarsyasProcessor> myMarsyasProcessor;
	ScopedPointer<MarsyasRealtime> marsyasRealtime;
	ScopedPointer<OpenNNClassifier> openNNClassifier;
	ScopedPointer<MarsyasPlayerNet> marsyasPlayerNet;
	float rolling_average_increase;
	float rolling_average_decrease;
	float current_rms;
	float previous_rms;
	float alpha_incr;
	float alpha_decr;
	int rolling_classification;
	//OpenNN::Vector<double> myVec;
	//std::vector<int> vector[3];
	OpenNN::Vector<int>* classificationCounters;
	bool not_processing;
	bool processing;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PluginCloneForGuitarAudioProcessor)
};
