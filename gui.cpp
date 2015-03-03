#include "gui.h"
#include <iostream>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout> 
#include "Answer.h"
#include <QString>
#include <vector>
#include <QMessageBox>

using namespace std;



GUI::GUI(Answer& ans)
{ 
  
  tagAndAnswer=ans.returnTagAndAnswer();
  tagAndQuestion=ans.returnTagAndQuestion();

  result=new QTextEdit;
  result->setReadOnly(true);
  
  string temp="Robots: ";
  temp=temp+tagAndQuestion["start"];
  QString qstr = QString::fromStdString(temp);
  result->append(qstr);
    //result->resize(800,400);

  vector<string> vec=tagAndAnswer["start"];
  answer[0]=vec[0];
  answer[1]=vec[1];
  QString button1Qstring = QString::fromStdString(answer[0]);
  QString button2Qstring = QString::fromStdString(answer[1]);

  optionButton[0] = new QPushButton(button1Qstring);
  optionButton[1] = new QPushButton(button2Qstring);
  optionButton[2] = new QPushButton("&3");
  optionButton[3] = new QPushButton("&4");
 

  //searchText = new QLineEdit;


 
  QVBoxLayout* optionColumn1 = new QVBoxLayout;//option columns
  QVBoxLayout* optionColumn2 = new QVBoxLayout;
  optionColumn1->addWidget(optionButton[0]);
  optionColumn1->addWidget(optionButton[1]);
  optionColumn2->addWidget(optionButton[2]);
  optionColumn2->addWidget(optionButton[3]);

  QHBoxLayout* optionLayout=new QHBoxLayout;
  optionLayout->addLayout(optionColumn1);
  optionLayout->addLayout(optionColumn2);



  QVBoxLayout* mainLayout = new QVBoxLayout;
  //mainLayout->addLayout(searchLine);
  //mainLayout->addWidget(select);
  mainLayout->addWidget(result);
  //mainLayout->addWidget(optionButton[0]);
  //mainLayout->addWidget(optionButton[1]);
  mainLayout->addLayout(optionLayout);

  connect(optionButton[0], SIGNAL(clicked()),
	  this,       SLOT(option1Clicked()));
  
  connect(optionButton[1], SIGNAL(clicked()),
	  this,       SLOT(option2Clicked()));

  connect(optionButton[2], SIGNAL(clicked()),
	  this,       SLOT(option3Clicked()));

  connect(optionButton[3], SIGNAL(clicked()),
	  this,       SLOT(option4Clicked()));


  optionButton[2]->setVisible(false);//default
  optionButton[3]->setVisible(false);
 

  //connect(result,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(_itemDoubleClicked(QListWidgetItem*)));

  setLayout(mainLayout);
}




GUI:: ~GUI()
{ 
  //delete searchText;
  delete optionButton[0];
  delete optionButton[1];
  delete optionButton[2];
  delete optionButton[3];
  delete result;

}

void GUI::option1Clicked()
{
	cout<<"option1Clicked"<<endl;

  if (answer[0]!="!@#$")
  {
    string temp="You: "+answer[0];
  QString qstr = QString::fromStdString(temp);
  result->append(qstr);
  result->append(" ");

  temp="Robots: ";
  temp=temp+tagAndQuestion[answer[0]];
  qstr = QString::fromStdString(temp);
  result->append(qstr);

  
  vector<string> vec=tagAndAnswer[answer[0]];

  if (vec[0]!="!@#$")
  {
    int size=vec.size();//number of answerwers
    for (int i=0;i<size;i++)
      {
         answer[i]=vec[i];
         optionButton[i]->setVisible(true);

        buttonQstring[i] = QString::fromStdString(answer[i]);
         optionButton[i]->setText(buttonQstring[i]);
         cout<<i<<endl;
      }

    for (int i=size;i<4;i++)
    {
     optionButton[i]->setVisible(false);
    }
  }
  else if (vec[0]=="!@#$")
  {
    optionButton[0]->setVisible(true);
    optionButton[1]->setVisible(true);
    optionButton[2]->setVisible(false);
    optionButton[3]->setVisible(false);

    answer[0]=vec[0];
    optionButton[0]->setText("Restart the conversation!");
    optionButton[1]->setText("No, I want to quit");
  }
 }
 else if (answer[0]=="!@#$")//press restart
 {
  result->clear();
  string temp="Robots: ";
  temp=temp+tagAndQuestion["start"];
  QString qstr = QString::fromStdString(temp);
  result->append(qstr);
    //result->resize(800,400);

  vector<string> vec=tagAndAnswer["start"];
  answer[0]=vec[0];
  answer[1]=vec[1];
  QString button1Qstring = QString::fromStdString(answer[0]);
  QString button2Qstring = QString::fromStdString(answer[1]);

  optionButton[0]->setText(button1Qstring);
  optionButton[1]->setText(button2Qstring);
 }
  
  
  
}


void GUI::option2Clicked()
{
	cout<<"option2Clicked"<<endl;
    if (answer[0]!="!@#$")
  {
    string temp="You: "+answer[1];
  QString qstr = QString::fromStdString(temp);
  result->append(qstr);
  result->append(" ");

  temp="Robots: ";
  temp=temp+tagAndQuestion[answer[1]];
  qstr = QString::fromStdString(temp);
  result->append(qstr);

  
  vector<string> vec=tagAndAnswer[answer[1]];

  if (vec[0]!="!@#$")
  {
    int size=vec.size();//number of answerwers
    for (int i=0;i<size;i++)
      {
         answer[i]=vec[i];
         optionButton[i]->setVisible(true);

        buttonQstring[i] = QString::fromStdString(answer[i]);
         optionButton[i]->setText(buttonQstring[i]);
         cout<<i<<endl;
      }

    for (int i=size;i<4;i++)
    {
     optionButton[i]->setVisible(false);
    }
  }
  else if (vec[0]=="!@#$")
  {
    optionButton[0]->setVisible(true);
    optionButton[1]->setVisible(true);
    optionButton[2]->setVisible(false);
    optionButton[3]->setVisible(false);

    answer[0]=vec[0];
    optionButton[0]->setText("Restart the conversation!");
    optionButton[1]->setText("No, I want to quit");
  }
 }
  else if (answer[0]=="!@#$")// press I want to quit
 {
  QMessageBox msgBox;
  msgBox.setText("Do you really want to quit this program?");
  msgBox.setStandardButtons(QMessageBox::Close | QMessageBox::Cancel);
  msgBox.setDefaultButton(QMessageBox::Cancel);
  int choice = msgBox.exec();

  switch (choice) {
   case QMessageBox::Close:
       this->close();
       break;
   case QMessageBox::Cancel:
       // Don't Save was clicked
       break;
   
   default:
       // should never be reached
       break;
    }
 }
}

void GUI::option3Clicked()
{
	cout<<"option3Clicked"<<endl;
    if (answer[2]!="!@#$")
  {
    string temp="You: "+answer[2];
  QString qstr = QString::fromStdString(temp);
  result->append(qstr);
  result->append(" ");

  temp="Robots: ";
  temp=temp+tagAndQuestion[answer[2]];
  qstr = QString::fromStdString(temp);
  result->append(qstr);

  
  vector<string> vec=tagAndAnswer[answer[2]];

  if (vec[0]!="!@#$")
  {
    int size=vec.size();//number of answerwers
    for (int i=0;i<size;i++)
      {
         answer[i]=vec[i];
         optionButton[i]->setVisible(true);

        buttonQstring[i] = QString::fromStdString(answer[i]);
         optionButton[i]->setText(buttonQstring[i]);
         //cout<<i<<endl;
      }

    for (int i=size;i<4;i++)
    {
     optionButton[i]->setVisible(false);
    }
  }
  else if (vec[0]=="!@#$")
  {
    optionButton[0]->setVisible(true);
    optionButton[1]->setVisible(true);
    optionButton[2]->setVisible(false);
    optionButton[3]->setVisible(false);

    answer[0]=vec[0];
    optionButton[0]->setText("Restart the conversation!");
    optionButton[1]->setText("No, I want to quit");
  }
 }
 else if (answer[2]=="!@#$")
 {
  result->clear();
  string temp="Robots: ";
  temp=temp+tagAndQuestion["start"];
  QString qstr = QString::fromStdString(temp);
  result->append(qstr);
    //result->resize(800,400);

  vector<string> vec=tagAndAnswer["start"];
  answer[0]=vec[0];
  answer[1]=vec[1];
  QString button1Qstring = QString::fromStdString(answer[0]);
  QString button2Qstring = QString::fromStdString(answer[1]);

  optionButton[0]->setText(button1Qstring);
  optionButton[1]->setText(button2Qstring);
 }
}

void GUI::option4Clicked()
{
	cout<<"option4Clicked"<<endl;

    cout<<"option3Clicked"<<endl;
    if (answer[3]!="!@#$")
  {
    string temp="You: "+answer[3];
  QString qstr = QString::fromStdString(temp);
  result->append(qstr);
  result->append(" ");

  temp="Robots: ";
  temp=temp+tagAndQuestion[answer[3]];
  qstr = QString::fromStdString(temp);
  result->append(qstr);

  
  vector<string> vec=tagAndAnswer[answer[3]];

  if (vec[0]!="!@#$")
  {
    int size=vec.size();//number of answerwers
    for (int i=0;i<size;i++)
      {
         answer[i]=vec[i];
         optionButton[i]->setVisible(true);

        buttonQstring[i] = QString::fromStdString(answer[i]);
         optionButton[i]->setText(buttonQstring[i]);
         cout<<i<<endl;
      }

    for (int i=size;i<4;i++)
    {
     optionButton[i]->setVisible(false);
    }
  }
  else if (vec[0]=="!@#$")
  {
    optionButton[0]->setVisible(true);
    optionButton[1]->setVisible(true);
    optionButton[2]->setVisible(false);
    optionButton[3]->setVisible(false);

    answer[0]=vec[0];
    optionButton[0]->setText("Restart the conversation!");
    optionButton[1]->setText("No, I want to quit");
  }
 }
 else if (answer[3]=="!@#$")
 {
  result->clear();
  string temp="Robots: ";
  temp=temp+tagAndQuestion["start"];
  QString qstr = QString::fromStdString(temp);
  result->append(qstr);
    //result->resize(800,400);

  vector<string> vec=tagAndAnswer["start"];
  answer[0]=vec[0];
  answer[1]=vec[1];
  QString button1Qstring = QString::fromStdString(answer[0]);
  QString button2Qstring = QString::fromStdString(answer[1]);

  optionButton[0]->setText(button1Qstring);
  optionButton[1]->setText(button2Qstring);
 }
}