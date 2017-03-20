#ifndef CHART_H_INCLUDED
#define CHART_H_INCLUDED

class Chart {
public:
    void setTitle( const std::string title ) {
        this->title = title;
    }
private:
    std::string title;
};

#endif // CHART_H_INCLUDED
