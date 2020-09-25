#ifndef VECTOR_HH
#define VECTOR_HH

class VectorInt
{
public:
  VectorInt();
  ~VectorInt();

  /*!
   * \brief front
   * \pre blocksize_ > 0
   * \return frontmost element
   */
  int front() const;

  /*!
   * \brief operator []
   * \param location
   * \pre blocksize_ > 0
   * \return element
   */
  int& operator[](int location);

  /*!
   * \brief at
   * \param location
   * \pre blocksize_ > 0
   * \return element
   */
  int& at(int location);

  /*!
   * \brief push_back
   * \pre blocksize_ > 0
   * \param element
   */
  void push_back(int element);

  /*!
   * \brief swap
   * \pre blocksize_ > 0
   * \param v
   */
  void swap(VectorInt& v);

private:
  int* datablock_; // This pointer will point to an array of integers allocated with new
  int blocksize_;  // Size of the allocated array
  int elementamount_;   // size of the area used from array
};

#endif // VECTOR_HH
