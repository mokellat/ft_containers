// #include "map/map.hpp"
// #include <thread>
// #include <chrono>
// #include <ctime>
// #include <sys/time.h>

// typedef ft::map<int, int>               MY_INT_MAP;
// typedef ft::map<int, int>::iterator     MY_INT_ITER;
// typedef std::map<int, int>              STD_INT_MAP;
// typedef std::map<int, int>::iterator    STD_INT_ITER;
// // using std::this_thread::sleep_for;

// # define RED "\033[31m"
// # define GREEN "\033[32m"
// # define OR "\033[34m"
// # define YELLOW "\033[33m"
// # define RESET "\033[0m"

// #define myprint(Y) std::cout << RESET << Y << std::endl
// #define green_print(Y) std::cout << GREEN << Y << std::endl
// #define yellow_print(Y) std::cout << YELLOW << Y << std::endl
// #define red_print(Y) std::cout << RED << Y << std::endl
// #define orange_print(Y) std::cout << OR << Y << std::endl

// time_t get_time(void)
// {
//     struct timeval time_now;

//     gettimeofday(&time_now, NULL);
//     time_t msecs_time = (time_now.tv_sec * 1e3) + (time_now.tv_usec / 1e3);
//     return (msecs_time);
// }

// int main()
// {
//     //insert--------------------------------------------------------------
//     red_print("insert using insert----------------------\n");
    
//     yellow_print("value comparaison****************************");

//     STD_INT_MAP     m;
//     STD_INT_ITER    it;

//     MY_INT_MAP      m1;
//     MY_INT_ITER     it1;

//     int size = 50;
//     for(int i = 0; i < size; i++)
//     {
//         it = m.insert({i-1, i}).first;
//         it1 = m1.insert(ft::pair<int, int>(i-1, i)).first;
//         if(it->first != it1->first)
//         {
//             red_print("ERROR: return value isnt correct");
//             break;
//         }        
//     }
//     green_print("OK: RETURN VALUE IS CORRECT");
//     myprint("\n");
//     // std::this_thread::sleep_for(300);

//     yellow_print("iterating over*******************");
//     it1 = m1.begin();
//     for(it = m.begin(); it != m.end(); ++it)
//     {
//         if(it->first != it1->first)
//         {
//             red_print("ERROR: iterators failed!");
//             break;
//         }
//         it1++;
//     }
//     green_print("OK: iterators check done");
//     myprint("\n\n");

//     // yellow_print("Time comparison****************************");
//     // time_t std_end;
//     // time_t std_start;
//     // time_t my_end;
//     // time_t my_start;

//     // size = 1000;
//     // std_start = get_time();
//     // for(int i = 0; i < size; i++)
//     // {
//     //     m.insert({i-1, i});
//     // }
//     // std_end = get_time();

//     // my_start = get_time();
//     // for(int i = 0; i < size; i++)
//     // {
//     //     m1.insert(ft::pair<int, int>(i-1, i));
//     // }
//     // my_end = get_time();
//     // myprint(std_end - std_start);
//     // myprint(my_end - my_start);


//     //copy constructor------------------------------------------------
//     red_print("copy constructor----------------------\n");
//     yellow_print("value comparaison****************************");

//     STD_INT_MAP     s_m;
//     STD_INT_ITER    s_it;
    
//     MY_INT_MAP      m1;
//     MY_INT_ITER     s_it2;

//     int size = 50;
//     m1()
//     green_print("OK: RETURN VALUE IS CORRECT");
//     myprint("\n");
//     // std::this_thread::sleep_for(300);

//     yellow_print("iterating over*******************");
//     s_it2 = m1.begin();
//     for(s_it = s_m.begin(); s_it != s_m.end(); ++s_it)
//     {
//         if(it->first != it2->first)
//         {
//             red_print("ERROR: iterators failed!");
//             break;
//         }
//         it2++;
//     }
//     green_print("OK: iterators check done");
//     myprint("\n\n");

//     return 0;
// }