#ifndef ANSWER_H
#define ANSWER_H
#include <string>
#include <vector>
#include <map>

using namespace std;

class Answer
{
public:
	Answer();
	~Answer();
	void readAnswer();
	map<string, vector<string> >& returnTagAndAnswer();
	map<string, string>& returnTagAndQuestion();
private:
	map<string, vector<string> > tagAndAnswer;
	map<string, string> tagAndQuestion;

};

#endif