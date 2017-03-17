//
//  AudioEngine.hpp
//  WorldGenerator
//
//  Created by Ryan Needham on 17/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef AudioEngine_hpp
#define AudioEngine_hpp

#include <OpenAL/al.h>
#include <OpenAL/alc.h>

#include "AudioObject.hpp"
#include "State.hpp"
#include <vector>

class AudioEngine {
    public:
        AudioEngine ();
       ~AudioEngine ();
    
        void playSounds (State s);
    
        void add (AudioObject* object);
    
    private:
        std::vector<AudioObject*> scene;
    
        ALCcontext *context;
        ALCdevice *device;
    
    
};

#endif /* AudioEngine_hpp */
