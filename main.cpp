#include "library.h"
#include <chrono>
#include <sstream>

using namespace std;

int main() {
    try {
        cout << "Enter Station ID (integer or string): ";
        string stationIDInput;
        cin >> stationIDInput;

        Station<string> station(stationIDInput);

        int numLines;
        cout << "Enter number of lines for this station: ";
        cin >> numLines;

        for (int i = 0; i < numLines; ++i) {
            cout << "Enter name for line " << i + 1 << ": ";
            string lineID;
            cin >> lineID;

            station.addLine(lineID);
            Line* line = station.getLine(lineID);

            int numTrains;
            cout << "Enter number of trains for line \"" << lineID << "\": ";
            cin >> numTrains;

            for (int j = 0; j < numTrains; ++j) {
                cout << "Press 1 if train " << j + 1 << " is a Through Train, 0 otherwise: ";
                bool isThroughTrain;
                cin >> isThroughTrain;

                bool isStoppingTrain = !isThroughTrain;

                cout << "Enter the arrival time of train " << j + 1 << " (in minutes from midnight - 00:00): ";
                int arrivalMinutes;
                cin >> arrivalMinutes;

                TrainSchedule schedule(arrivalMinutes, isStoppingTrain);

                try {
                    line->getPlatform().scheduleTrain(schedule);
                    cout << "Train " << j + 1 << " scheduled successfully.\n";
                } catch (const InvalidScheduleException& ex) {
                    cerr << "Error: " << ex.what() << "\n";
                }
            }
        }

        cout << "\nStation ID: " << station.getStationID() << "\n";

        for (const auto& line : station.getLines()) {
            cout << "Line: " << line.getLineID() << "\n";

            cout << "  Stoppage Trains (30 mins interval): ";
            for (const auto& schedule : line.getPlatform().getSchedules()) {
                if (schedule.getIsStoppingTrain()) {
                    cout << schedule.getArrivalMinutes() << " ";
                }
            }
            cout << "\n";

            cout << "  Through Trains (10 mins interval): ";
            for (const auto& schedule : line.getPlatform().getSchedules()) {
                if (!schedule.getIsStoppingTrain()) {
                    cout << schedule.getArrivalMinutes() << " ";
                }
            }
            cout << "\n";
        }

    } catch (const exception& ex) {
        cerr << "Error: " << ex.what() << endl;
    }

    return 0;
}
