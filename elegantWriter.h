#ifndef ELEGANTWRITER_H
#define ELEGANTWRITER_H

#include <QTextStream>
#include <QString>
#include <QByteArray>
#include <QStringView>

#include <windows.h>

namespace os{

    enum class Color{
        black, blue, green, cyan, red, magenta, brown,lightGray,
        darkGray, lightBlue, lightGreen, lightCyan, lightRed,
        lightMagenta, yellow, white
    };//Class Color

    class ElegantWriter{
    public:
        inline explicit ElegantWriter() { };
        inline explicit ElegantWriter(const Color c) { setColor(c); };

        inline friend void operator<<(ElegantWriter&, bool t){ write<bool>(t);                      }
        inline friend void operator<<(ElegantWriter&, char t){ write<char>(t);                      }
        inline friend void operator<<(ElegantWriter&, short t){ write<short>(t);                    }
        inline friend void operator<<(ElegantWriter&, unsigned short t){ write<unsigned short>(t);  }
        inline friend void operator<<(ElegantWriter&, char16_t t){ write<char16_t>(t);              }
        inline friend void operator<<(ElegantWriter&, char32_t t){ write<char32_t>(t);              }
        inline friend void operator<<(ElegantWriter&, int t){ write<int>(t);                        }
        inline friend void operator<<(ElegantWriter&, unsigned int t){ write<unsigned int>(t);      }
        inline friend void operator<<(ElegantWriter&, long t){ write<long>(t);                      }
        inline friend void operator<<(ElegantWriter&, unsigned long t){ write<unsigned long>(t);    }
        inline friend void operator<<(ElegantWriter&, qint64 t){ write<qint64>(t);                  }
        inline friend void operator<<(ElegantWriter&, quint64 t){ write<quint64>(t);                }
        inline friend void operator<<(ElegantWriter&, float t){ write<float>(t);                    }
        inline friend void operator<<(ElegantWriter&, double t){ write<double>(t);                  }
        inline friend void operator<<(ElegantWriter&, const char* t){ write<const char*>(t);        }
        inline friend void operator<<(ElegantWriter&, const QString& t){ write<const QString&>(t);  }
        inline friend void operator<<(ElegantWriter&, QStringView t){ write<QStringView>(t);        }
        inline friend void operator<<(ElegantWriter&, const QByteArray t){ write<QByteArray>(t);    }

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

    };//Class ElegantWriter

}//namespace os

#endif // ELEGANTWRITER_H
