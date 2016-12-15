/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  WorleyMachine.hpp
 *  Tribes
 *
 *  Created by Ryan Needham on 02/12/2016.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef WorleyMachine_hpp
#define WorleyMachine_hpp

#include "../Utility/Vertex.hpp"
#include <vector>

class WorleyMachine {
    public:
        static void initialise ();
    
        static double noise (double xin, double yin);
        static double noise (double xin, double yin, double zin);
        static double noise (double xin, double yin, double zin, double win);
    
    private:

};

#endif /* WorleyMachine_hpp */
