#ifndef MACLASSE_H
#define MACLASSE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MaClasse; }
QT_END_NAMESPACE

class MaClasse : public QMainWindow
{
    Q_OBJECT

public:
    MaClasse(QWidget *parent = nullptr);
    ~MaClasse();

private:
    Ui::MaClasse *ui;
};
#endif // MACLASSE_H
