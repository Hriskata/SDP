#include <iostream>
#include <vector>
#include <deque>

struct Patient
{
    int index;
    bool emergency;
};

void Queue_patient(int NumberOfMedic, int _NumberOfPatients)
{
    int indexOfDoctor = 0;
    std::deque<Patient> PatientsQueue;
    std::vector<std::vector<Patient>> Hospital;
    std::string temp_emer;
    for (int i = 0; i < NumberOfMedic; i++)
    {
        std::vector<Patient> temp;
        Hospital.push_back(temp);
    }
    for (int i = 0; i < _NumberOfPatients; i++)
    {
        Patient p;
        p.index = i;
        std::cin >> temp_emer;
        if (temp_emer == "Y")
            p.emergency = true;
        else p.emergency = false;

        if (p.emergency == true)
            PatientsQueue.push_front(p);
        else PatientsQueue.push_back(p);

    }

    while (!PatientsQueue.empty())
    {

        if (indexOfDoctor == NumberOfMedic)
        {
            indexOfDoctor = 0;
        }
        Patient p = PatientsQueue.front();
        Hospital[indexOfDoctor++].push_back(p);
        PatientsQueue.pop_front();
    }

    for (int i = 0; i < NumberOfMedic; i++)
    {
        int size = Hospital[i].size();
        std::cout << "Doctor: " << i << std::endl;
        for (int j = 0; j < size; j++)
        {
            std::cout << "Patient index: " << Hospital[i][j].index << std::endl;
        }
    }

}

int main()
{
    int NumberOfMedic;
    int NumberOfPatients;
    std::cout << "Enter number of doctors: ";
    std::cin >> NumberOfMedic;
    std::cout << "Enter number of patients: ";
    std::cin >> NumberOfPatients;
    std::cout << "Enter 'Y' if its emergency! "<<std::endl;
    Queue_patient(NumberOfMedic,NumberOfPatients);

    return 0;
}
