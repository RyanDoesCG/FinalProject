//
//  SafeCounter.hpp
//  WorldGenerator
//
//  Created by user on 15/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef SafeCounter_hpp
#define SafeCounter_hpp

class SafeCounter {
    public: SafeCounter (float v, float mn, float mx): value(v), min(mn), max(mx) {}
    public: void increment   () { value += (value < max) ? 1 : 0; }
    public: void decrement   () { value -= (value > min) ? 1 : 0; }
    public: void incrementBy (float v) { value += (value + v < max) ? v : 0; }
    public: void decrementBy (float v) { value -= (value - v > min) ? v : 0; }
    public: void transform   (float v) { if (v > 0) incrementBy(v); if (v < 0) decrementBy(v); }
    public: void setValue    (float v) { if (v > min && v < max) { value = v; } }
    public: float getValue   () { return value; }
    
    private: float value;
    private: float min;
    private: float max;
};

#endif /* SafeCounter_hpp */
