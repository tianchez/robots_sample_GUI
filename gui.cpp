#include "gui.h"
#include <iostream>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout> 
#include "Answer.h"

using namespace std;



GUI::GUI(Answer& ans)
{ 
  
  tagAndAnswer=ans.returnTagAndAnswer();
  tagAndQuestion=ans.returnTagAndQuestion();

  option1Button = new QPushButton("&Yes");
  option2Button = new QPushButton("&NO");
  option3Button = new QPushButton("&3");
  option4Button = new QPushButton("&4");
 

  //searchText = new QLineEdit;


  result=new QTextEdit;
  result->setReadOnly(true);
  result->append("Robots: Are you a USC student?");
    //result->resize(800,400);
  QVBoxLayout* optionColumn1 = new QVBoxLayout;//option columns
  QVBoxLayout* optionColumn2 = new QVBoxLayout;
  optionColumn1->addWidget(option1Button);
  optionColumn1->addWidget(option2Button);
  optionColumn2->addWidget(option3Button);
  optionColumn2->addWidget(option4Button);

  QHBoxLayout* optionLayout=new QHBoxLayout;
  optionLayout->addLayout(optionColumn1);
  optionLayout->addLayout(optionColumn2);



  QVBoxLayout* mainLayout = new QVBoxLayout;
  //mainLayout->addLayout(searchLine);
  //mainLayout->addWidget(select);
  mainLayout->addWidget(result);
  //mainLayout->addWidget(option1Button);
  //mainLayout->addWidget(option2Button);
  mainLayout->addLayout(optionLayout);

  connect(option1Button, SIGNAL(clicked()),
	  this,       SLOT(option1Clicked()));
  
  connect(option2Button, SIGNAL(clicked()),
	  this,       SLOT(option2Clicked()));

  connect(option3Button, SIGNAL(clicked()),
	  this,       SLOT(option3Clicked()));

  connect(option4Button, SIGNAL(clicked()),
	  this,       SLOT(option4Clicked()));


  option3Button->setVisible(false);//default
  option4Button->setVisible(false);
 

  //connect(result,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(_itemDoubleClicked(QListWidgetItem*)));

  setLayout(mainLayout);
}




GUI:: ~GUI()
{ 
  //delete searchText;
  delete option1Button;
  delete option2Button;
  delete result;

}

void GUI::option1Clicked()
{
	cout<<"option1Clicked"<<endl;
}

void GUI::option2Clicked()
{
	cout<<"option2Clicked"<<endl;
}

void GUI::option3Clicked()
{
	cout<<"option3Clicked"<<endl;
}

void GUI::option4Clicked()
{
	cout<<"option4Clicked"<<endl;
}