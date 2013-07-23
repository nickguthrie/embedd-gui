////////////////////////////////////////////////////////////////////////////////
/**
 *  @file channel.cpp
 *  @brief
 *
 *  DETAILED DESCRIPTION
 *  
 *  @title channel
 *  @author Nicholas Guthrie
 *  @web http//nickguthrie.com/embedd_gui/doc
 *  @created July 23, 2013
 * 
 */
////////////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------ :Libraries:
//                      _    _ _                 _        
//                     | |  (_) |__ _ _ __ _ _ _(_)___ ___
//                     | |__| | '_ \ '_/ _` | '_| / -_|_-<
//                     |____|_|_.__/_| \__,_|_| |_\___/__/
//                                                        
// -----------------------------------------------------------------------------
#include "channel.h"
// Input-Output
#include <iostream>             /* input-output stream - necessary for cout */
//#include <fstream>            /* to use file stream */
using namespace std;            /* to not need std:: on all io */  
//Strings
#include <string>             /* to use strings */
#include <sstream>            /* use strings like cout */
//#include <cstdlib>            /* for atoi */
//#include <cctype>             /* for atoi */
//#include <vector>
//#include <map>  
//Math
//#include <math>               /* pow, sqrt and use compile flag -lm */ 
//#include <algorithm>          /* use sort and find */


//--------------------------------------------------------------- :Constructors:
//                ___             _               _              
//               / __|___ _ _  __| |_ _ _ _  _ __| |_ ___ _ _ ___
//              | (__/ _ \ ' \(_-<  _| '_| || / _|  _/ _ \ '_(_-<
//               \___\___/_||_/__/\__|_|  \_,_\__|\__\___/_| /__/
//                                                               
// -----------------------------------------------------------------------------
////////////////////////////////////////////////////////////////////////////////
/**
 *  @brief Default constructor for a channel.
 */
////////////////////////////////////////////////////////////////////////////////
channel::channel()
{
    min = 0;
    max = 4096;
    value = 0;
}
////////////////////////////////////////////////////////////////////////////////
/**
 *  @brief Constructs a channel with a minimum and a maximum size.
 */
////////////////////////////////////////////////////////////////////////////////
channel::channel( int min_size, int max_size)
{
    min = min_size;
    max = max_size;
    value = 0;
}
//------------------------------------------------------------------- :Mutators:
//                     __  __      _        _              
//                    |  \/  |_  _| |_ __ _| |_ ___ _ _ ___
//                    | |\/| | || |  _/ _` |  _/ _ \ '_(_-<
//                    |_|  |_|\_,_|\__\__,_|\__\___/_| /__/
//                                                         
// -----------------------------------------------------------------------------
////////////////////////////////////////////////////////////////////////////////
/**
 *  @brief Sets the current value for the channel.
 *  @warning No error handling if given a bad value to set.
 */
////////////////////////////////////////////////////////////////////////////////
void channel::set_value( int size )
{
    //if( size < max && size > min )
    value = size;
}
////////////////////////////////////////////////////////////////////////////////
/**
 *  @brief Sets the minimum and maximum sizes for a channel.
 */
////////////////////////////////////////////////////////////////////////////////
void channel::set_size( int min_size, int max_size )
{
    min = min_size;
    max = max_size;
}
////////////////////////////////////////////////////////////////////////////////
/**
 *  @brief Sets the minimum and maximum sizes for a channel.
 */
////////////////////////////////////////////////////////////////////////////////
void channel::incrament()
{
    set_value(value + 1);
}
////////////////////////////////////////////////////////////////////////////////
/**
 *  @brief Decraments the value by one;
 */
////////////////////////////////////////////////////////////////////////////////
void channel::decrament()
{
    set_value(value - 1);
}

//------------------------------------------------------------------ :Accessors:
//                        _                               
//                       /_\  __ __ ___ ______ ___ _ _ ___
//                      / _ \/ _/ _/ -_|_-<_-</ _ \ '_(_-<
//                     /_/ \_\__\__\___/__/__/\___/_| /__/
//                                                        
// -----------------------------------------------------------------------------
////////////////////////////////////////////////////////////////////////////////
/**
 *  @brief 
 *  @warning 
 *  @param[in] 
 *  @return
 */
////////////////////////////////////////////////////////////////////////////////
int channel::get_value () const
{
    return value;
}
////////////////////////////////////////////////////////////////////////////////
/**
 *  @brief Returns the maximum allowed value for a chanel
 *  @return The max allowed value.
 */
////////////////////////////////////////////////////////////////////////////////
int channel::get_max () const
{
    return max;
}
////////////////////////////////////////////////////////////////////////////////
/**
 *  @brief Returns the maximum allowed value for a chanel
 *  @return The max allowed value.
 */
////////////////////////////////////////////////////////////////////////////////
int channel::get_min () const
{
    return min;
}
////////////////////////////////////////////////////////////////////////////////
/**
 *  @brief 
 *  @warning 
 *  @param[in] 
 *  @return
 */
////////////////////////////////////////////////////////////////////////////////
std::string channel::get_svalue () const
{
    string result;           // string which will contain the result
    ostringstream convert;   // stream used for the conversion
    convert << value;        // insert the txt representation of 'value' in the
			     // characters in the stream
    result = convert.str();  // set 'Result' to the contents of the stream
    return result;
}




// ////////////////////////////////////////////////////////////////////////////////
// //
// // Channel Holder
// //
// ////////////////////////////////////////////////////////////////////////////////
// //--------------------------------------------------------------- :Constructors:
// //                ___             _               _              
// //               / __|___ _ _  __| |_ _ _ _  _ __| |_ ___ _ _ ___
// //              | (__/ _ \ ' \(_-<  _| '_| || / _|  _/ _ \ '_(_-<
// //               \___\___/_||_/__/\__|_|  \_,_\__|\__\___/_| /__/
// //                                                               
// // -----------------------------------------------------------------------------
// ////////////////////////////////////////////////////////////////////////////////
// /**
//  *  @brief Constructs a channel holder that holds a group of channels.
//  */
// ////////////////////////////////////////////////////////////////////////////////
// channel_holder::channel_holder( int num_channels )
// {
//     mode = 0;
//     size = num_channels;
//     //Allocate channels
//     holder = new channel[num_channels];
//     //Question - Does this construct using default constructors correctly?
// }
// //------------------------------------------------------------------ :Accessors:
// //                        _                               
// //                       /_\  __ __ ___ ______ ___ _ _ ___
// //                      / _ \/ _/ _/ -_|_-<_-</ _ \ '_(_-<
// //                     /_/ \_\__\__\___/__/__/\___/_| /__/
// //                                                        
// // -----------------------------------------------------------------------------
// ////////////////////////////////////////////////////////////////////////////////
// /**
//  *  @brief Gets the number of channels stored in the holder.
//  *  @return The number of channels stored.
//  */
// ////////////////////////////////////////////////////////////////////////////////
// int channel_holder::get_size () const
// {
//     return size;
// }
// ////////////////////////////////////////////////////////////////////////////////
// /**
//  *  @brief Returns the current mode the channel is set to.
//  *  @return The current mode set.
//  */
// ////////////////////////////////////////////////////////////////////////////////
// int channel_holder::get_mode () const
// {
//     return mode;
// }
// ////////////////////////////////////////////////////////////////////////////////
// /**
//  *  @brief Gets a channel to modify.
//  *  @return The specified channel
//  */
// ////////////////////////////////////////////////////////////////////////////////
// channel * channel_holder::get_channel (int num )
// {
//     channel * ret_chan = channel[num];
//     return ret_chan;
// }

