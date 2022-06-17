#ifndef __STRING__ITERATOR__HPP__
#define __STRING__ITERATOR__HPP__

class StringIterator
{
public:
    typedef std::random_access_iterator_tag  iterator_category;
    typedef char  iterator_type;
    typedef iterator_type  value_type;
    typedef ptrdiff_t  difference_type;
    typedef iterator_type&  reference;
    typedef iterator_type*  pointer;

public:
    StringIterator(const StringIterator&);

private:
    StringIterator(std::size_t, char*);

public:
    StringIterator& operator = (const StringIterator&);
    bool operator != (const StringIterator&) const;
    bool operator == (const StringIterator&) const;
    typename StringIterator::reference operator * () const;
    StringIterator& operator + (int);
    StringIterator operator - (int);
    StringIterator& operator ++ () ;
    StringIterator& operator -- ();
    StringIterator operator ++ (int);
    StringIterator operator -- (int);
    StringIterator& operator += (int);
    StringIterator& operator -= (int);
    bool operator < (const StringIterator&) const;
    bool operator > (const StringIterator&) const;
    bool operator >= (const StringIterator&) const;
    bool operator <= (const StringIterator&) const;
    typename StringIterator::difference_type operator - (const StringIterator&);
    void swap(StringIterator&);

    
private:
    friend class String;
    friend std::ostream& operator << (std::ostream& print, const StringIterator&);



private:
    std::size_t _m_index {};
    char* value {};
};

#include "String.hpp"
#include "IteratorImplementation.hpp"


#endif
