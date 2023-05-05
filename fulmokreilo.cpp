#include <iostream>
#include <string>
#include <cmath>
#include <Magick++.h>
#include <random>

using namespace Magick;

std::string fKreiFulmon(int profundeco) { //Создание молнии
    if (profundeco == 0) {
        return "F";
    }
    std::string gxisnuno = fKreiFulmon(profundeco - 1);
    std::string rezulto = "";
    for (char c : gxisnuno) {
        if (c == 'F') {
            rezulto += "F+F--F+F";
        } else {
            rezulto += c;
        }
    }
    return rezulto;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "Uzado: " << argv[0] << " <dosiernomo> <pasxo>" << std::endl;
        return 1;
    }
    std::string dosiernomo = argv[1];
    int pasxo = std::stoi(argv[2]);

    InitializeMagick(nullptr);
    Image bildo(Geometry(512, 512), ColorRGB(0, 0, 0));

    std::string fulmo = fKreiFulmon(5);

    int x = 256;
    int y = 512;

    double angulo = -M_PI / 2;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-M_PI / 6, M_PI / 6);
    std::uniform_int_distribution<> dis_pasxo(pasxo - 2, pasxo + 2);

    for (char c : fulmo) {
        if (c == 'F') {
            int x2 = x + dis_pasxo(gen) * cos(angulo);
            int y2 = y + dis_pasxo(gen) * sin(angulo);
            bildo.strokeColor(ColorRGB(1, 1, 1));
            bildo.strokeWidth(1);
            bildo.draw(DrawableLine(x, y, x2, y2));
            x = x2;
            y = y2;
        } else if (c == '+') {
            angulo += dis(gen);
        } else if (c == '-') {
            angulo -= dis(gen);
        }
    };
    
    Image bildo2(bildo);
    //bildo2.channel(AlphaChannel);
    bildo2.transparent(Color("black"));
    bildo2.blur(0, 5);
    //bildo2.level(QuantumRange * 0.5, QuantumRange, 1.0);
    bildo.composite(bildo2, 0, 0, DstOverCompositeOp);
    bildo.flop();
    bildo.write(dosiernomo);

    return 0;
}
