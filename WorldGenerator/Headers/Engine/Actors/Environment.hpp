/* * * * * * * * * * * * * * *
 *
 * * * * * * * * * * * * * * */
 #ifndef Environment_hpp
 #define Environment_hpp

class Environment {
    public:
        Environment();
       ~Environment();
    
    protected:
        float temperature;
        float percipitationChance;
        float windSpeed;
    
        enum Type { DESERT, FOREST, VOLCANIC, TROPICAL, ARCTIC, max };
        Type type;
        void determinType ();
    
};

 #endif /* Environment_hpp */
