#include <QApplication>
#include "gui.h"
#include "Answer.h"




int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  Answer ans;
  ans.readAnswer();
  GUI gui(ans);
  gui.setWindowTitle("Frank's sample GUI");
  gui.show();
  return app.exec();

}
