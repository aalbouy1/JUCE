#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

#include "Faust_layout.h"

// Select here the compiled DSP that you want to executev  
//#include "DSP files/noise.cpp"
//#include "DSP files/kisana.cpp"
<<<<<<< HEAD
//#include "DSP files/faust_dsp.h"
//#include "DSP Files/faust_dsp - tab.h"
//#include "DSP Files/matrix.cpp"
#include "DSP files/karplus.cpp"
//#include "DSP Files/karplus32.cpp"
//#include "DSP Files/UITester.cpp"
=======
#include "DSP files/faust_dsp.h"
//#include "DSP files/faust_dsp - tab.h"
//#include "DSP files/karplus.cpp"
//#include "DSP Files/karplus32.cpp"
>>>>>>> f8f6f7f91bec8d2105baca28e416d84de417da3c

std::list<GUI*> GUI::fGuiList;

class MainContentComponent   : public AudioAppComponent, private Timer
{
public:
    MainContentComponent()
    {
        fDSP = new mydsp();
        
<<<<<<< HEAD
        fDSP->buildUserInterface(&layout);
        getMinSize();
        
        addAndMakeVisible(layout);
        //layout.render();
        
        setSize (minWidth, minHeight);
=======
        fDSP->buildUserInterface(&flexBox);
        getMinSize();
        
        setSize (minWidth, minHeight);
        addAndMakeVisible(flexBox);
>>>>>>> f8f6f7f91bec8d2105baca28e416d84de417da3c
        
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
        layout.Faust_layout::paint(g);
    }
    
    void resized() override
    {
        layout.Faust_layout::setFlexBoxSize(getWindowWidth(), getWindowHeight());
        layout.Faust_layout::resized();
        std::cout<<"Resizing.."<<std::endl;
        
    }
    
    float getWindowHeight(){
        return this->getHeight();
    }
    
    float getWindowWidth(){
        return this->getWidth();
    }

    int getMinWidth(){
        return minWidth;
    }

    int getMinHeight(){
        return minHeight;
    }

    void getMinSize(){
<<<<<<< HEAD
        minHeight = layout.getMinimumHeight();
        minWidth = layout.getMinimumWidth();
    }

=======
        minHeight = flexBox.getMinimumHeight();
        minWidth = flexBox.getMinimumWidth();
    }


>>>>>>> f8f6f7f91bec8d2105baca28e416d84de417da3c
private:

    Faust_layout layout;

    ScopedPointer<mydsp> fDSP;
    
<<<<<<< HEAD
    int minHeight = 300;
    int minWidth = 200;
=======
    int minHeight = 400;
    int minWidth = 400;
>>>>>>> f8f6f7f91bec8d2105baca28e416d84de417da3c
    
    Rectangle<int> screen = Desktop::getInstance().getDisplays().getMainDisplay().userArea;
    int screenWidth = screen.getWidth();
    int screenHeight = screen.getHeight();
    
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


// (This function is called by the app startup code to create our main component)
MainContentComponent* createMainContentComponent()     { return new MainContentComponent(); }


#endif