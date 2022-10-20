#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class PointInfo {
public:
    PointInfo(int xIn, int yIn, int vX, int vY) : x(xIn), y(yIn), vx(vX), vy(vY) {}
    int getX(int time) const
    {
        return x + (vx*time);
    }
    int getY(int time) const
    {
        return y + (vy*time);
    }
    bool isSame(int xIn, int yIn, int time) const
    {
        bool ret = (getX(time) == xIn) && (getY(time) == yIn);
        return ret;
    }
private:
    int x, y, vx, vy;
};

bool extractPointsInfo(std::string inputString, std::vector<PointInfo>& info)
{
    try {
        size_t linePos = 0;
        do {
            size_t startX = inputString.find_first_of("<", linePos) + 1;

            size_t endX = inputString.find_first_of(",", startX);
            std::string x = inputString.substr(startX, endX - startX);

            size_t startY = endX + 1;
            size_t endY = inputString.find_first_of(">", startY);
            std::string y = inputString.substr(startY, endY - startY);

            size_t startVx = inputString.find_first_of("<", endY) + 1;
            size_t endVX = inputString.find_first_of(",", startVx);
            std::string Vx = inputString.substr(startVx, endVX - startVx);

            size_t startVy = endVX + 1;
            size_t endVy = inputString.find_first_of(">", startVy);
            std::string Vy = inputString.substr(startVy, endVy - startVy);


            info.push_back(PointInfo(std::stoi(x), std::stoi(y), std::stoi(Vx), std::stoi(Vy)));

            if (inputString.find_first_of("position", endVy) == std::string::npos) {
                return true;
            }
            linePos = endVy;
        } while (1);
    }
    catch (...) {
        std::cout << "Extracting points info failed! Check the input string" << std::endl;
        return false;
    }
}

void printPosition(std::vector<PointInfo>& pointsInfo, int time, int xMin, int xMax, int yMin, int yMax)
{
    std::sort(pointsInfo.begin(), pointsInfo.end(), [time] (const PointInfo& p1, const PointInfo& p2) {
                                                        if (p1.getY(time) < p2.getY(time)) {
                                                            return true;
                                                        }
                                                        else if (p1.getY(time) == p2.getY(time)) {
                                                            return p1.getX(time) < p2.getX(time);
                                                        }
                                                        else {
                                                            return false;
                                                        }
                                                    });
    pointsInfo.erase(std::unique(pointsInfo.begin(), pointsInfo.end(), [time](const PointInfo& p1, const PointInfo& p2) {
                                return p1.isSame(p2.getX(time), p2.getY(time), time);
                                }),
                    pointsInfo.end());
    int x, y;
    auto it = pointsInfo.begin();
    for (y = yMin ; y <= yMax; y++ ){
        std::cout << std::endl;
        for(x = xMin; x <= xMax; x++) {
            if (it != std::end(pointsInfo) && it->isSame(x, y, time)) {
                std::cout << "# ";
                it++;
            }
            else {
                std::cout << ". ";
            }
        }
    }
    std::cout << std::endl;
}
int main() {
    std::string inputString = R"(position=< 9,  1> velocity=< 0,  2>
                                position=< 7,  0> velocity=<-1,  0>
                                position=< 3, -2> velocity=<-1,  1>
                                position=< 6, 10> velocity=<-2, -1>
                                position=< 2, -4> velocity=< 2,  2>
                                position=<-6, 10> velocity=< 2, -2>
                                position=< 1,  8> velocity=< 1, -1>
                                position=< 1,  7> velocity=< 1,  0>
                                position=<-3, 11> velocity=< 1, -2>
                                position=< 7,  6> velocity=<-1, -1>
                                position=<-2,  3> velocity=< 1,  0>
                                position=<-4,  3> velocity=< 2,  0>
                                position=<10, -3> velocity=<-1,  1>
                                position=< 5, 11> velocity=< 1, -2>
                                position=< 4,  7> velocity=< 0, -1>
                                position=< 8, -2> velocity=< 0,  1>
                                position=<15,  0> velocity=<-2,  0>
                                position=< 1,  6> velocity=< 1,  0>
                                position=< 8,  9> velocity=< 0, -1>
                                position=< 3,  3> velocity=<-1,  1>
                                position=< 0,  5> velocity=< 0, -1>
                                position=<-2,  2> velocity=< 2,  0>
                                position=< 5, -2> velocity=< 1,  2>
                                position=< 1,  4> velocity=< 2,  1>
                                position=<-2,  7> velocity=< 2, -2>
                                position=< 3,  6> velocity=<-1, -1>
                                position=< 5,  0> velocity=< 1,  0>
                                position=<-6,  0> velocity=< 2,  0>
                                position=< 5,  9> velocity=< 1, -2>
                                position=<14,  7> velocity=<-2,  0>
                                position=<-3,  6> velocity=< 2, -1>)";


    std::vector<PointInfo> pointsInfo;
    if (extractPointsInfo(inputString, pointsInfo)) {
        int time = 3;

        int xMin = std::max_element(pointsInfo.begin(), pointsInfo.end(), [time](const PointInfo& p1, const PointInfo& p2) {
                                                                                return p1.getX(time) > p2.getX(time);
                                                                            })->getX(time);
        int xMax = std::max_element(pointsInfo.begin(), pointsInfo.end(), [time](const PointInfo& p1, const PointInfo& p2) {
                                                                                return p1.getX(time) < p2.getX(time);
                                                                            })->getX(time);
        int yMin = std::max_element(pointsInfo.begin(), pointsInfo.end(), [time](const PointInfo& p1, const PointInfo& p2) {
                                                                                return p1.getY(time) > p2.getY(time);
                                                                            })->getY(time);
        int yMax = std::max_element(pointsInfo.begin(), pointsInfo.end(), [time](const PointInfo& p1, const PointInfo& p2) {
                                                                                return p1.getY(time) < p2.getY(time);
                                                                            })->getY(time);

        printPosition(pointsInfo, time, xMin, xMax, yMin, yMax);

    }
    return 0;
}
