//
//  AudioObject.hpp
//  WorldGenerator
//
//  Created by Ryan Needham on 17/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef AudioObject_hpp
#define AudioObject_hpp

#include <OpenAL/OpenAL.h>
#include <OpenAL/alc.h>
#include <AudioToolbox/AudioServices.h>
#include <string>

class AudioObject {
    public:
        AudioObject (std::string name);
       ~AudioObject ();
    
        virtual void play ();
    
    private:
        void load (const std::string name);
    
        char*     alBuffer;             //data for the buffer
        ALenum alFormatBuffer;    //buffer format
        ALsizei   alFreqBuffer;       //frequency
        long       alBufferLen;        //bit depth
        ALboolean    alLoop;         //loop
        unsigned int alSource;      //source
        unsigned int alSampleSet;
};

#endif /* AudioObject_hpp */
