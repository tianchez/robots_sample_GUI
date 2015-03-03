#include <iostream>
#include "Answer.h"
#include <string>
#include <vector>
#include <map>

using namespace std;

Answer::Answer()
{

}

Answer::~Answer()
{
	
}

void Answer::readAnswer()//hard code for now
{	

	vector<string> tempAnswer;//1st blcok
	
	string ques="Are you a USC student?";
	string tag="start";
	string ans1="Yes";
	string ans2="No";
	string ans3;
	string ans4;
	tempAnswer.push_back(ans1);
	tempAnswer.push_back(ans2);
	tagAndAnswer.emplace(tag,tempAnswer);
	tagAndQuestion.emplace(tag,ques);

	
	ques="Are you an undergraduate student or graduate student?";//2nd blcok
	tag="Yes";
	ans1="undergrads!";
	ans2="grads!";
	tempAnswer.clear();
	tempAnswer.push_back(ans1);
	tempAnswer.push_back(ans2);
	tagAndAnswer.emplace(tag,tempAnswer);
	tagAndQuestion.emplace(tag,ques);

	ques="Do you know USC before?";//3rd blcok
	tag="No";
	ans1="I know";
	ans2="full name of USC?";
	tempAnswer.clear();
	tempAnswer.push_back(ans1);
	tempAnswer.push_back(ans2);
	tagAndAnswer.emplace(tag,tempAnswer);
	tagAndQuestion.emplace(tag,ques);

	ques="The University of Southern California (USC)is a private, not-for-profit, nonsectarian, research university founded in 1880 with its main campus in the city area of Los Angeles, California. As California's oldest private research university, USC has historically educated a large number of the region's business leaders and professionals. In recent decades, the university has also leveraged its location in Los Angeles to establish relationships with research and cultural institutions throughout Asia and the Pacific Rim. In 2011, USC was named among the Top 10 Dream Colleges in the nation.\n \n Do you want to know more about USC?";//4th blcok
	tag="full name of USC?";
	ans1="Yes, I want";
	ans2="No, thanks";
	tempAnswer.clear();
	tempAnswer.push_back(ans1);
	tempAnswer.push_back(ans2);
	tagAndAnswer.emplace(tag,tempAnswer);
	tagAndQuestion.emplace(tag,ques);

	ques="Are you an alumni of USC?";//5th blcok
	tag="I know";
	ans1="Yeah!";
	ans2="No, I'm not";
	tempAnswer.clear();
	tempAnswer.push_back(ans1);
	tempAnswer.push_back(ans2);
	tagAndAnswer.emplace(tag,tempAnswer);
	tagAndQuestion.emplace(tag,ques);

	ques="Which year are you in right now?";//6th blcok
	tag="undergrads!";
	ans1="Freshman";
	ans2="Sophomore";
	ans3="Junior";
	ans4="Senior";
	tempAnswer.clear();
	tempAnswer.push_back(ans1);
	tempAnswer.push_back(ans2);
	tempAnswer.push_back(ans3);
	tempAnswer.push_back(ans4);
	tagAndAnswer.emplace(tag,tempAnswer);
	tagAndQuestion.emplace(tag,ques);

	ques="It is your contribution to USC that makes USC.renowned in a fame of research university. Keep researching! Fight on!Welcome back! USC is always the second home of yours! ";//7th blcok
	tag="grads!";
	ans1="!@#$";
	ans2="!@#$";
	tempAnswer.clear();
	tempAnswer.push_back(ans1);
	tempAnswer.push_back(ans2);
	tagAndAnswer.emplace(tag,tempAnswer);
	tagAndQuestion.emplace(tag,ques);

	ques="Are you working at USC right now?";//8th blcok
	tag="No, I'm not";
	ans1="Yes,I am";
	ans2="I am sorry, I am not";
	tempAnswer.clear();
	tempAnswer.push_back(ans1);
	tempAnswer.push_back(ans2);
	tagAndAnswer.emplace(tag,tempAnswer);
	tagAndQuestion.emplace(tag,ques);

	ques="Thank you so much for your contribution to USC. I believe that your dedication to USC can make USC more prestigious!";//9th blcok
	tag="Yes,I am";
	ans1="!@#$";
	ans2="!@#$";
	tempAnswer.clear();
	tempAnswer.push_back(ans1);
	tempAnswer.push_back(ans2);
	tagAndAnswer.emplace(tag,tempAnswer);
	tagAndQuestion.emplace(tag,ques);

	ques="Here is the link of detailed imformation of USC.\n http://en.wikipedia.org/wiki/University_of_Southern_California. \n \n I hope these information can make you know more about USC!";//11th blcok
	tag="Yes, I want";
	ans1="!@#$";
	ans2="!@#$";
	tempAnswer.clear();
	tempAnswer.push_back(ans1);
	tempAnswer.push_back(ans2);
	tagAndAnswer.emplace(tag,tempAnswer);
	tagAndQuestion.emplace(tag,ques);

	ques="Have you been to USC before?";//12th blcok
	tag="I am sorry, I am not";
	ans1="I did";
	ans2="No, I hope so";
	tempAnswer.clear();
	tempAnswer.push_back(ans1);
	tempAnswer.push_back(ans2);
	tagAndAnswer.emplace(tag,tempAnswer);
	tagAndQuestion.emplace(tag,ques);

	ques="I hope this conversation can make you more familiar to USC!";//13th blcok
	tag="No, thanks";
	ans1="!@#$";
	ans2="!@#$";
	tempAnswer.clear();
	tempAnswer.push_back(ans1);
	tempAnswer.push_back(ans2);
	tagAndAnswer.emplace(tag,tempAnswer);
	tagAndQuestion.emplace(tag,ques);

	ques="There are still 4 more interesting years waiting for you. Enjoy the time in USC!";//14th blcok
	tag="Freshman";
	ans1="!@#$";
	ans2="!@#$";
	tempAnswer.clear();
	tempAnswer.push_back(ans1);
	tempAnswer.push_back(ans2);
	tagAndAnswer.emplace(tag,tempAnswer);
	tagAndQuestion.emplace(tag,ques);

	ques="You've been in USC for 2 years. Try to find something more excited in rest of 3 years!";//15th blcok
	tag="Sophomore";
	ans1="!@#$";
	ans2="!@#$";
	tempAnswer.clear();
	tempAnswer.push_back(ans1);
	tempAnswer.push_back(ans2);
	tagAndAnswer.emplace(tag,tempAnswer);
	tagAndQuestion.emplace(tag,ques);

	ques="Two more years left for your college time! Are you ready for paying back to trojan family?";//16th blcok
	tag="Junior";
	ans1="!@#$";
	ans2="!@#$";
	tempAnswer.clear();
	tempAnswer.push_back(ans1);
	tempAnswer.push_back(ans2);
	tagAndAnswer.emplace(tag,tempAnswer);
	tagAndQuestion.emplace(tag,ques);

	ques="You've almost finished your time in USC. I hope the time in USC can be one of the best in your whole life!";//17th blcok
	tag="Senior";
	ans1="!@#$";
	ans2="!@#$";
	tempAnswer.clear();
	tempAnswer.push_back(ans1);
	tempAnswer.push_back(ans2);
	tagAndAnswer.emplace(tag,tempAnswer);
	tagAndQuestion.emplace(tag,ques);

	ques="Trojan family is always welcoming your next visit to USC!";//18th blcok
	tag="I did";
	ans1="!@#$";
	ans2="!@#$";
	tempAnswer.clear();
	tempAnswer.push_back(ans1);
	tempAnswer.push_back(ans2);
	tagAndAnswer.emplace(tag,tempAnswer);
	tagAndQuestion.emplace(tag,ques);

	ques="Here is the location of USC.  We hope you can visit USC if you like! \n https://maps.google.com/maps?safe=active&q=university+of+southern+california&bav=on.2,or.&bvm=bv.87269000,d.cGU&biw=1536&bih=704&dpr=1.25&um=1&ie=UTF-8&sa=X&ei=xofyVJfeCJeIoQSSoYLgDw&ved=0CAYQ_AUoAQ";//19th blcok
	tag="No, I hope so";
	ans1="!@#$";
	ans2="!@#$";
	tempAnswer.clear();
	tempAnswer.push_back(ans1);
	tempAnswer.push_back(ans2);
	tagAndAnswer.emplace(tag,tempAnswer);
	tagAndQuestion.emplace(tag,ques);

	return;


}


map<string, vector<string> >& Answer::returnTagAndAnswer()
{
	return tagAndAnswer;
}

map<string, string>& Answer::returnTagAndQuestion()
{
	return tagAndQuestion;
}