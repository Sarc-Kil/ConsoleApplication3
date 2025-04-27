#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Participant {
public:
    string name;
    string email;

    Participant(const string& name, const string& email) : name(name), email(email) {}
};

class Ticket {
public:
    Participant participant;
    string eventTitle;

    Ticket(const Participant& participant, const string& eventTitle)
        : participant(participant), eventTitle(eventTitle) {
    }
};

class Venue {
public:
    string name;
    string address;
    int capacity;

    Venue(const string& name, const string& address, int capacity)
        : name(name), address(address), capacity(capacity) {
    }
};

class Event {
public:
    string title;
    Venue venue;
    string date;
    vector<Ticket> tickets;

    Event(const string& title, const Venue& venue, const string& date)
        : title(title), venue(venue), date(date) {
    }

    void registerParticipant(const Participant& participant) {
        if (tickets.size() < venue.capacity) {
            tickets.push_back(Ticket(participant, title));
            cout << "�������� " << participant.name << " ��������������� �� ������� \"" << title << "\"." << endl;
        }
        else {
            cout << "��� ��������� ���� ��� ������� \"" << title << "\"." << endl;
        }
    }
};

class Schedule {
public:
    vector<Event> events;

    void addEvent(const Event& event) {
        events.push_back(event);
    }

    void displaySchedule() const {
        cout << "���������� �������:" << endl;
        for (const auto& event : events) {
            cout << "�������: " << event.title << " | ����: " << event.date
                << " | �����: " << event.venue.name << endl;
        }
    }
};

class Feedback {
public:
    string eventTitle;
    string participantName;
    string comment;

    Feedback(const string& eventTitle, const string& participantName, const string& comment)
        : eventTitle(eventTitle), participantName(participantName), comment(comment) {
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    Schedule schedule;

    string venueName, venueAddress;
    int venueCapacity;
    cout << "������� �������� ����� ����������: ";
    getline(cin, venueName);
    cout << "������� ����� ����� ����������: ";
    getline(cin, venueAddress);
    cout << "������� ����������� �����: ";
    cin >> venueCapacity;
    cin.ignore();

    Venue venue(venueName, venueAddress, venueCapacity);

    string eventTitle, eventDate;
    cout << "������� �������� �������: ";
    getline(cin, eventTitle);
    cout << "������� ���� �������: ";
    getline(cin, eventDate);

    Event event(eventTitle, venue, eventDate);
    schedule.addEvent(event);

    int participantCount;
    cout << "������� ���������� ����������: ";
    cin >> participantCount;
    cin.ignore();

    for (int i = 0; i < participantCount; ++i) {
        string participantName, participantEmail;
        cout << "������� ��� ���������: ";
        getline(cin, participantName);
        cout << "������� email ���������: ";
        getline(cin, participantEmail);
        Participant participant(participantName, participantEmail);
        event.registerParticipant(participant);
    }

    schedule.displaySchedule();

    string feedbackComment;
    cout << "������� ����� ��� ������� \"" << eventTitle << "\": ";
    getline(cin, feedbackComment);
    Feedback feedback(eventTitle, event.tickets.back().participant.name, feedbackComment);
    cout << "����� �� " << feedback.participantName << " � ������� \"" << feedback.eventTitle << "\": " << feedback.comment << endl;

    return 0;
}