#include <iostream>
#include <string>

int main(){

    std::string word1, word2, word3;
    std::cout << "Enter three words: \n";
    std::cin >> word1;
    std::cin >> word2;
    std::cin >> word3;

    std::string sentence = word1 + " " + word2 + " " + word3 + ".";
    std::cout << sentence;

    std::cout << "\nThe words have a length of " << word1.length() << ", " << word2.length() << " and " << word3.length() << "." << std::endl;
    std::cout << "The entire sentence has a length of " << sentence.length() << "." << std::endl;  // Add this to show the entire sentence length

    std::string sentence2 = sentence;

    if (sentence2.length() >= 12) {
        for (int i = 9; i <= 11; ++i) {
            sentence2[i] = 'x';
        }
    }

    std::cout << sentence << std::endl;
    std::cout << sentence2 << std::endl;

    if(sentence.length() >= 5) {
        std::string sentence_start = sentence.substr(0, 5);
        std::cout << "Sentence: " << sentence << std::endl;
        std::cout << "Sentence start: " << sentence_start << std::endl;
    }

    if (sentence.find("hallo") != std::string::npos) {
        std::cout << "The sentence contains the word 'hallo'." << std::endl;
    } else {
        std::cout << "The sentence does not contain the word 'hallo'." << std::endl;
    }

    size_t pos = sentence.find("er");
    while (pos != std::string::npos) {
        std::cout << "'er' found at position: " << pos << std::endl;
        pos = sentence.find("er", pos + 1);  // Start the next search from the position after the last found occurrence
    }

    return 0;
}
