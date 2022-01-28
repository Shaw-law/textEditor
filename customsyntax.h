#ifndef CUSTOMSYNTAX_H
#define CUSTOMSYNTAX_H

#include <Qsci/qscilexercustom.h>

class customSyntax : public QsciLexerCustom {
public:
  customSyntax(QsciScintilla *parent = nullptr);
};

#endif // CUSTOMSYNTAX_H
