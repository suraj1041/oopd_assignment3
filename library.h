#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <cmath>

using namespace std;

class TrainSchedule {
private:
    int arrivalMinutes;
    bool isStoppingTrain;

public:
    TrainSchedule(int arrivalMinutes, bool isStoppingTrain)
        : arrivalMinutes(arrivalMinutes), isStoppingTrain(isStoppingTrain) {}

    bool getIsStoppingTrain() const {
        return isStoppingTrain;
    }

    int getArrivalMinutes() const {
        return arrivalMinutes;
    }
};

class InvalidScheduleException : public runtime_error {
public:
    explicit InvalidScheduleException(const string& message)
        : runtime_error(message) {}
};

class Platform {
private:
    vector<TrainSchedule> trainSchedules;

public:
    void scheduleTrain(const TrainSchedule& newTrain) {
        for (const auto& existingTrain : trainSchedules) {
            int timeDifference = abs(newTrain.getArrivalMinutes() - existingTrain.getArrivalMinutes());

            if (newTrain.getArrivalMinutes() >= existingTrain.getArrivalMinutes()) {
                if (existingTrain.getIsStoppingTrain()) {
                    if (timeDifference < 30) {
                        throw InvalidScheduleException("Schedule conflicts with an existing train schedule.");
                    }
                } else {
                    if (timeDifference < 10) {
                        throw InvalidScheduleException("Schedule conflicts with an existing train schedule.");
                    }
                }
            } else {
                if (newTrain.getIsStoppingTrain()) {
                    if (timeDifference < 30) {
                        throw InvalidScheduleException("Schedule conflicts with an existing train schedule.");
                    }
                } else {
                    if (timeDifference < 10) {
                        throw InvalidScheduleException("Schedule conflicts with an existing train schedule.");
                    }
                }
            }
        }
        trainSchedules.push_back(newTrain);
    }

    const vector<TrainSchedule>& getSchedules() const {
        return trainSchedules;
    }
};

class Line {
private:
    string lineID;
    Platform platform;

public:
    explicit Line(const string& lineID) : lineID(lineID) {}

    string getLineID() const {
        return lineID;
    }

    Platform& getPlatform() const {
        return const_cast<Platform&>(platform);
    }
};

template <typename IDType>
class Station {
private:
    IDType stationID;
    vector<Line> lines;

public:
    explicit Station(IDType id) : stationID(id) {}

    IDType getStationID() const {
        return stationID;
    }

    void addLine(const string& lineID) {
        lines.emplace_back(lineID);
    }

    Line* getLine(const string& lineID) {
        for (auto& line : lines) {
            if (line.getLineID() == lineID) {
                return &line;
            }
        }
        return nullptr;
    }

    const vector<Line>& getLines() const {
        return lines;
    }
};

#endif
