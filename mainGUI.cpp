#include <QApplication>
#include "gui.h"
#include "Answer.h"




int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  Answer ans;
  ans.readAnswer();
  GUI gui(ans);
  gui.setWindowTitle("Tianchen Zhang's searching engine");
  gui.show();
  return app.exec();

}
