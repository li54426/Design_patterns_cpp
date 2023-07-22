// 策略接口
class SortingStrategy
{
public:
    virtual void sort(std::vector<int>& data) = 0;
};

// 冒泡排序策略
class BubbleSort : public SortingStrategy
{
public:
    void sort(std::vector<int>& data) override;
};

// 快速排序策略
class QuickSort : public SortingStrategy
{
public:
    void sort(std::vector<int>& data) override;
};

// 客户端
class Client
{
public:
    Client(SortingStrategy* strategy) : m_strategy(strategy) {}
    void setSortingStrategy(SortingStrategy* strategy) { m_strategy = strategy; }
    void sort(std::vector<int>& data) { m_strategy->sort(data); }
private:
    SortingStrategy* m_strategy;
};