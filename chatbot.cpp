#include <iostream>
#include <unordered_map>
#include <string>
#include <ctime>
#include<algorithm>
using namespace std;
bool hasKeyword(const string& input, const string& keyword){
    string lowercaseInput = input;
    transform(lowercaseInput.begin(), lowercaseInput.end(), lowercaseInput.begin(), ::tolower);
    return lowercaseInput.find(keyword) != string::npos;
    }
int main() {

    time_t currentTime = time(nullptr);
    string currentTimeString = ctime(&currentTime);

    unordered_map<string, string> responses {
        {"hi", "Hello! How can I assist you?"},
        {"how are you", "I'm good, thank you!"},
        {"bye", "Goodbye! Have a great day!"},
        {"time", currentTimeString},
        {"date", currentTimeString},
        {"tell me about yourself","I am an AI-powered chatbot designed to provide assistance and engage in conversation. How can I help you today?"},
        {"What can you do?", "I can provide information, answer questions, and assist you with various tasks. Feel free to ask me anything!"},
        
    };
    
  

    string input;

    cout << "Chatbot: Hello! How can I assist you?" << endl;

    while (true) {
        cout << "User: ";
        getline(cin, input);
        // cin>>input;
        bool foundResponse = false;
        if (input.length()!=0) {
            for (const auto& response : responses) {
            if (hasKeyword(input, response.first)) {
                cout << "Chatbot: " << response.second << endl;
                foundResponse = true;
                break;
              } 
            }
            if(!foundResponse)
            {
                cout << "Chatbot: I'm sorry, I don't understand. Can you please rephrase your question?" << endl;
            }
            
        } 
       

        if (input == "bye") {
            break;
        }
    }

    return 0;
}
