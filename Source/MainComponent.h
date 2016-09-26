#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

#include "juceFlexBox.h"

//#include "noise.cpp"
//#include "kisana.cpp"
#include "faust_dsp.h"
//#include "karplus.cpp"

std::list<GUI*> GUI::fGuiList;

class MainContentComponent   : public AudioAppComponent, private Timer
{
public:
    MainContentComponent()
    {
        fDSP = new mydsp();
        
        fDSP->buildUserInterface(&flexBox);
        
        setSize (400, 800);
        addAndMakeVisible(flexBox);
        
        setAudioChannels (fDSP->getNumInputs(), fDSP->getNumOutputs());
        
        startTimerHz(25);
    }
    
    ~MainContentComponent()
    {
        stopTimer();
        shutdownAudio();
    }
    
    void timerCallback() override
    {
        GUI::updateAllGuis();
    }

    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override
    {
        fDSP->init(int(sampleRate));
    }
    
    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override
    {
        const float* inputs[fDSP->getNumInputs()];
        for (int i = 0; i < fDSP->getNumInputs(); i++) {
            inputs[i] = bufferToFill.buffer->getReadPointer(i, bufferToFill.startSample);
        }
        
        float* outputs[fDSP->getNumOutputs()];
        for (int i = 0; i < fDSP->getNumOutputs(); i++) {
            outputs[i] = bufferToFill.buffer->getWritePointer(i, bufferToFill.startSample);
        }
        
        fDSP->compute(bufferToFill.numSamples, (float**)inputs, outputs);
    }
    
    void releaseResources() override
    {
    }

    void paint (Graphics& g) override
    {
        flexBox.JuceUI::paint(g);
    }
    
    void resized() override
    {
        flexBox.setFlexBoxSize(getWindowWidth(), getWindowHeight());
        flexBox.JuceUI::resized();
        std::cout<<"Resizing.."<<std::endl;
        
    }
    
    float getWindowHeight(){
        return this->getHeight();
    }
    
    float getWindowWidth(){
        return this->getWidth();
    }
    
private:

    JuceUI flexBox;
    
    ScopedPointer<mydsp> fDSP;
    
    int minHeight = 800;
    int minWidth = 400;
    
    Rectangle<int> screen = Desktop::getInstance().getDisplays().getMainDisplay().userArea;
    int screenWidth = screen.getWidth();
    int screenHeight = screen.getHeight();
    
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


// (This function is called by the app startup code to create our main component)
Component* createMainContentComponent()     { return new MainContentComponent(); }


#endif