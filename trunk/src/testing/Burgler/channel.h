#ifndef CHANNEL_H
#define CHANNEL_H

#include <string>

////////////////////////////////////////////////////////////////////////////////
/**
 *  @class channel
 *  @brief Stores information about each channel.
 *
 *  DETAILED NOTES
 */
////////////////////////////////////////////////////////////////////////////////  
class channel
{
private:
    //////////////////////////////
    // Members
    //////////////////////////////  
    int min;
    int max;
    int value;
    // string name; /* worth including a name? */
    
public:
    //////////////////////////////
    // Constructors
    //////////////////////////////
    channel();
    channel( int min_size, int max_size );
    
    //////////////////////////////
    // Accessors
    //////////////////////////////
    int get_value () const;
    int get_max () const;
    int get_min () const;
    std::string get_svalue () const;
    
    //////////////////////////////
    // Mutators
    //////////////////////////////
    void set_value( int size );
    void set_size( int min_size, int max_size );
};
/* //////////////////////////////////////////////////////////////////////////////// */
/* /\** */
/*  *  @class channel_holder */
/*  *  @brief  */
/*  * */
/*  *  DETAILED NOTES */
/*  *\/ */
/* ////////////////////////////////////////////////////////////////////////////////   */
/* class channel_holder */
/* { */
/* private: */
/*     ////////////////////////////// */
/*     // Members */
/*     //////////////////////////////   */
/*     int size; */
/*     int mode; */
/*     channel * holder; */

/* public: */
/*     ////////////////////////////// */
/*     // Constructors */
/*     ////////////////////////////// */
/*     channel_holder( int num_channels ); */

/*     ////////////////////////////// */
/*     // Accessors */
/*     ////////////////////////////// */
/*     int get_size () const; */
/*     int get_mode () const; */
/*     channel * get_channel ( int num ); */
    
/*     ////////////////////////////// */
/*     // Mutators */
/*     ////////////////////////////// */
/* }; */

#endif // CHANNEL_H
