#ifndef ELEGANTWRITER_H
#define ELEGANTWRITER_H

#include <QTextStream>
#include <QString>
#include <QByteArray>
#include <QStringView>
#include <QChar>
#include <QLatin1Char>

#include <windows.h>

namespace os{

    enum class Color{
        black, blue, green, cyan, red, magenta, brown,lightGray,
        darkGray, lightBlue, lightGreen, lightCyan, lightRed,
        lightMagenta, yellow, white
    };//Class Color

    class ElegantWriter{
        using elWr = ElegantWriter;
    public:
        inline explicit ElegantWriter() { };
        inline explicit ElegantWriter(const Color c) { setColor(c); };

        inline friend void operator<<(elWr&, QChar t)             { write<QChar>(t);          }
        inline friend void operator<<(elWr&, char t)              { write<char>(t);           }
        inline friend void operator<<(elWr&, char16_t t)          { write<char16_t>(t);       }
        inline friend void operator<<(elWr&, short t)             { write<short>(t);          }
        inline friend void operator<<(elWr&, unsigned short t)    { write<unsigned short>(t); }
        inline friend void operator<<(elWr&, int t)               { write<int>(t);            }
        inline friend void operator<<(elWr&, unsigned int t)      { write<unsigned int>(t);   }
        inline friend void operator<<(elWr&, long t)              { write<long>(t);           }
        inline friend void operator<<(elWr&, unsigned long t)     { write<unsigned long>(t);  }
        inline friend void operator<<(elWr&, qlonglong t)         { write<qlonglong>(t);      }
        inline friend void operator<<(elWr&, qulonglong t)        { write<qulonglong>(t);     }
        inline friend void operator<<(elWr&, float t)             { write<float>(t);          }
        inline friend void operator<<(elWr&, double t)            { write<double>(t);         }
        inline friend void operator<<(elWr&, const QString& t)    { write<const QString&>(t); }
        inline friend void operator<<(elWr&, QStringView t)       { write<QStringView>(t);    }
        inline friend void operator<<(elWr&, QLatin1String t)     { write<QLatin1String>(t);  }
        inline friend void operator<<(elWr&, const QByteArray& t) { write<QByteArray>(t);     }
        inline friend void operator<<(elWr&, const char* t)       { write<const char*>(t);    }

        inline friend void operator>>(elWr&, QChar &t)            { read<QChar&>(t);          }
        inline friend void operator>>(elWr&, char& t)             { read<char&>(t);           }
        inline friend void operator>>(elWr&, short& t)            { read<short>(t);           }
        inline friend void operator>>(elWr&, unsigned short& t)   { read<unsigned short&>(t); }
        inline friend void operator>>(elWr&, int& t)              { read<int&>(t);            }
        inline friend void operator>>(elWr&, unsigned int& t)     { read<unsigned int&>(t);   }
        inline friend void operator>>(elWr&, long& t)             { read<long&>(t);           }
        inline friend void operator>>(elWr&, unsigned long& t)    { read<unsigned long&>(t);  }
        inline friend void operator>>(elWr&, qlonglong& t)        { read<qlonglong&>(t);      }
        inline friend void operator>>(elWr&, qulonglong& t)       { read<qulonglong&>(t);     }
        inline friend void operator>>(elWr&, float& t)            { read<float&>(t);          }
        inline friend void operator>>(elWr&, double& t)           { read<double&>(t);         }
        inline friend void operator>>(elWr&, QString& t)          { read<QString&>(t);        }
        inline friend void operator>>(elWr&, QByteArray& t)       { read<QByteArray&>(t);     }

        inline void setColor(const Color c) const noexcept{
            const int color { static_cast<int>(c) };
            const HANDLE hConsole { GetStdHandle(STD_OUTPUT_HANDLE) };
            SetConsoleTextAttribute(hConsole, color);
        }

    private:
        template <typename T>
        inline static void write(T arg)  noexcept{
            QTextStream out(stdout);
            out << arg;
            out.flush();
        };


        template <typename T>
        inline static void read(T arg)  noexcept{
            QTextStream cin(stdin);
            cin >> arg;
        };

    };//Class ElegantWriter

}//namespace os

#endif // ELEGANTWRITER_H
