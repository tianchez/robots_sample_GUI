#ifndef GUI_H
#define GUI_H
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <string>
#include <list>
#include <map>
#include "Answer.h"

using namespace std;


class GUI: public QWidget
{
	Q_OBJECT
public:
  //MyForm(map<string, WebPage>& p, QWidget* parent = NULL);
  //GUI();
  GUI(Answer& ans);
  ~GUI();
  // Help define initial size
  QSize sizeHint() const { return QSize( 800, 600 ); }
  // Not totally useful in the main widget/window
  QSize minimumSizeHint() const { return QSize( 400, 300 );}
 private slots:
  //void clearClicked();
  //void sendClicked();
  void option1Clicked();
  void option2Clicked();
  void option3Clicked();
  void option4Clicked();
  //void _itemDoubleClicked(QListWidgetItem* item);

protected:
  //void mousePressEvent(QMouseEvent* ev);
 private:
 // QLineEdit* searchText;

  //map<string, List<string> > tree;
  map<string, vector<string> > tagAndAnswer;
  map<string, string> tagAndQuestion;
  QPushButton* option1Button;
  QPushButton* option2Button;
  QPushButton* option3Button;
  QPushButton* option4Button;
  QTextEdit* result;
  
 };


#endif