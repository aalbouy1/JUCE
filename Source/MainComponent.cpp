/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

#include "faust/gui/LayoutManagerUI.h"
#include "faust/gui/APIUI.h"

#include "JUCEUI.h"

#include "faust_dsp.h"

std::list<GUI*> GUI::fGuiList;
ztimedmap GUI::gTimedZoneMap;

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainContentComponent : public AudioAppComponent
{
    
    public:
    
        //==============================================================================
        MainContentComponent()
        {
            //fOpenGLContext.attachTo(*this);
            fDSP = new mydsp();
            
            // Prepare layout wth the component size
            fLayoutUI = new LayoutManagerUI();
            fDSP->buildUserInterface(fLayoutUI);
            fLayoutUI->setSize(1024, 768);
            
            fJUCEUI = new JUCEUI(this, fLayoutUI);
            fDSP->buildUserInterface(fJUCEUI);
            fDSP->buildUserInterface(&fAPIUI);
            
            fLayoutUI->write(&std::cout);

            // specify the number of input and output channels that we want to open
            setAudioChannels(fDSP->getNumInputs(), fDSP->getNumOutputs());
            
            setSize(1024, 768);
        }

        ~MainContentComponent()
        {
            fOpenGLContext.detach();
            shutdownAudio();
            delete fDSP;
            delete fJUCEUI;
            delete fLayoutUI;
        }

        //==============================================================================
        void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override
        {
            // This function will be called when the audio device is started, or when
            // its settings (i.e. sample rate, block size, etc) are changed.

            // You can use this function to initialise any resources you might need,
            // but be careful - it will be called on the audio thread, not the GUI thread.

            // For more details, see the help for AudioProcessor::prepareToPlay()
            
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
            //std::cout << "Faust numSamples " << bufferToFill.numSamples << std::endl;
        }
 
        void releaseResources() override
        {
            // This will be called when the audio device stops, or when it is being
            // restarted due to a setting change.

            // For more details, see the help for AudioProcessor::releaseResources()
        }

        //==============================================================================
        void paint (Graphics& g) override
        {
            // (Our component is opaque, so we must completely fill the background with a solid colour)
            g.fillAll (Colours::floralwhite);

            //g.drawText("Faust example", 100, 50, 100, 100,  Justification::centredLeft);

            // You can add your drawing code here!
            
            /*
            getLookAndFeel().drawLevelMeter (g, getWidth(), getHeight(),
                                             0.5); // (add a bit of a skew to make the level more obvious)
            */
        }

        void resized() override
        {
            // This is called when the MainContentComponent is resized.
            // If you add any child components, this is where you should
            // update their positions.
            
            if (fLayoutUI) {
                fLayoutUI->setSize(getWidth(), getHeight());
                fJUCEUI->resized();
            }
            
           std::cout << "resized " << getWidth() << " " << getHeight()  << std::endl;
        }


    private:
        //==============================================================================

        // Your private member variables go here...
        dsp* fDSP;
        JUCEUI* fJUCEUI;
        LayoutManagerUI* fLayoutUI;
        APIUI fAPIUI;
        OpenGLContext fOpenGLContext;
 
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


// (This function is called by the app startup code to create our main component)
Component* createMainContentComponent()     { return new MainContentComponent(); }


#endif  // MAINCOMPONENT_H_INCLUDED
