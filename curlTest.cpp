#include <string>
#include <iostream>
#include <curl/curl.h>

using namespace std;

//
// For this demonstration, the contents of the web page are put
// into this global variable.
//

//similar to Java strings, but not as friendly 
string contents = ""; //initilize the string to the empty string 

//
// This is the callback function that is called by
// curl_easy_perform(curl)
//
size_t handle_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
    //calculating the number of bytes that you are going to be dealing in this function
    int numbytes = size*nmemb;

    // The data is not null-terminated, so get the last character, and replace
    // it with '\0'... strings are terminated with \0 in old C++
    char lastchar = *((char *) ptr + numbytes - 1);
    *((char *) ptr + numbytes - 1) = '\0';

    contents.append((char *)ptr); //using the modern string this to append to it 
    contents.append(1,lastchar); 

    *((char *) ptr + numbytes - 1) = lastchar;  // Might not be necessary... depends on the string library if you need this 
    return size*nmemb;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cerr << "use: curltest url\n";
        return -1;
    }

    //creates a variable of type curl 
    CURL* curl = curl_easy_init();

    if(curl) //if the variable has soemthing in it, checking if curl is equal to 0 (null)
    {
        // Tell libcurl the URL
        curl_easy_setopt(curl,CURLOPT_URL, argv[1]);
        // Tell libcurl what function to call when it has data
        curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,handle_data); //what function should I "callback" when I get data 
        // Do it!
        CURLcode res = curl_easy_perform(curl); //this is going to block until it gets the whole contents of the URL 
        curl_easy_cleanup(curl);
        //if everything worked out

        if (res == 0) //if the eroro code is zero if everything went well 
        {
            cout << contents << endl;

            string temp = "";
            for(int i = 0; i < 5; i++)
            {
                temp += contents[i];
            }
            cout << temp << endl;
        }
        else
        {
            //res would be the return type... "Did it all go well"
            cerr << "Error: " << res << endl;
        }
    }
    return 0;
}