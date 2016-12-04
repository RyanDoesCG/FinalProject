
#ifndef Moon_hpp
#define Moon_hpp

#include "Model.hpp"

class Moon : public Model {
    public:
        Moon ();
       ~Moon ();
    
        virtual void update (GameState state, SceneCamera* camera) override;
    
    private:
    
};

#endif /* Moon.hpp */
