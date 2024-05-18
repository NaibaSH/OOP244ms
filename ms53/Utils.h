/*/////////////////////////////////////////////////////////////////////////
                         OOP244 Ms53:
Full Name  : Shabanova Naiba
Student ID#: 164598229
Email      : nshabanova@myseneca.ca
Section    : ZCC
Date       : 2024.04.06
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#ifndef SENECA_UTILS_H_
#define SENECA_UTILS_H_
#include <iostream>
using namespace std;
namespace seneca {
    class Utils {
        /// <summary>
        /// Start point for the simulated time
        /// Set to 8 AM
        /// </summary>
        unsigned int m_testMins = 480;
        /// <summary>
        /// index for the time addition intervals ({ 3,5,9,20,30 });
        /// </summary>
        unsigned int m_testIndex = 0;
    public:
        /// <summary>
        /// Set the debug global variable to true and sets the m_testMins attribute to 
        ///  hour x 60 + min. This value will be the intial starting time for debugging
        ///  and testing. 
        /// </summary>
        /// <param name="hour">hours</param>
        /// <param name="min">minutes</param>
        void setDebugTime(int hour, int min);
        /// <summary>
        /// If not in debugging mode, returns the current minute value of the system hour
        ///  and minute. If debugging is active it will first return the value of m_testMins 
        ///  then adds the following values in these intervals (3,5,9,20,30) to simulate passage
        ///  of time. 
        /// </summary>
        /// <returns>the current time in minutes</returns>
        int getTime(); // returns the time of day in minutes

        /// <summary>
        /// compares s1 to s2
        /// </summary>
        /// <param name="s1">Cstring</param>
        /// <param name="s2">Cstring</param>
        /// <returns> &gt;0 if s1 &gt; s2  OR  &lt;0 if s1 &lt; s2 OR 0 if s1 = s2</returns>
        int strcmp(const char* s1, const char* s2)const;

        /// <summary>
        /// Calculates the length of a null-terminated string.
        /// </summary>
        /// <param name="str">Cstring</param>
        /// <returns>The length of the string.</returns>
        size_t strlen(const char* str);

        /// <summary>
        /// Copies the null-terminated string pointed to 'src' to the array pointed to 'des'.
        /// </summary>
        /// <param name="des">Pointer to the destination array</param>
        /// <param name="src">Pointer to the source Cstring</param>
        /// <returns>A pointer to 'des'.</returns>
        char* strcpy(char* des, const char* src);

        /// <summary>
        /// Deletes the memory pointed to 'des', allocates new memory, and copies the null-terminated string pointed to 'src' into 'des'.
        /// </summary>
        /// <param name="des">Reference to the pointer to the destination array</param>
        /// <param name="src">Pointer to the source Cstring</param>
        void aloCopy(char*& des, const char* src);

        /// <summary>
        /// Reads an integer value from the standard input
        /// </summary>
        /// <returns>Valid integer input</returns>
        int getInt();

        /// <summary>
        /// Reads a C-string from the standard input
        /// </summary>
        /// <param name="str">Pointer to the destination array</param>
        /// <param name="len">Maximum length of the string to be read</param>
        void getCstr(char* str, size_t len);

    };
    /// <summary>
       /// making seneca::debug variable global to all the files
       /// which include "Utils.h"
       /// </summary>
    extern bool debug;
    /// <summary>
    /// making seneca::U "Utils" object global to all the files which include "Utils.h"
    /// </summary>
    extern Utils U;

}
template <typename type>
void removeDynamicElement(type* array[], int index, int& size) {
   delete array[index];
   for (int j = index; j < size; j++) {
      array[j] = array[j + 1];
   }
   size--;
}
#endif // !SENECA_UTILS_H_


