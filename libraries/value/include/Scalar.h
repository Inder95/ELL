////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Project:  Embedded Learning Library (ELL)
//  File:     Scalar.h (value)
//  Authors:  Kern Handa
//
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Value.h"
#include "ScalarOperations.h"

namespace ell
{
namespace value
{

/// <summary> Wraps a Value instance and enforces a memory layout that represents a single value </summary>
class Scalar
{
public:
    Scalar();

    /// <summary> Constructor that wraps the provided instance of Value </summary>
    /// <param name="value"> The Value instance to wrap </param>
    Scalar(Value value);

    /// <summary> Constructs an instance from a fundamental type value </summary>
    /// <typeparam name="T"> Any fundamental type accepted by Value </typeparam>
    /// <param name="t"> The value to wrap </param>
    template <typename T>
    Scalar(T t) : Scalar(Value(t)) { }

    /// <summary> Conversion function that returns the underlying wrapped Value instance </summary>
    explicit operator Value() const;

    /// <summary> Creates a new Scalar instance that contains the same value as this instance </summary>
    /// <returns> A new Scalar instance that points to a new, distinct memory that contains the same value as this instance </returns>
    Scalar Copy() const;

    /// <summary> Arithmetic operators </summary>
    Scalar& operator+=(Scalar);
    Scalar& operator*=(Scalar);
    Scalar& operator-=(Scalar);
    Scalar& operator/=(Scalar);

    /// <summary> Retrieve the underlying value as a fundamental type </summary>
    /// <typeparam name="T"> The C++ fundamental type that is being retrieved from the instance </typeparam>
    /// <returns> If the wrapped Value instance's type matches that of the fundamental type, returns the value, otherwise throws </returns>
    template <typename T>
    T Get() const
    {
        return *_value.Get<T*>();
    }

    /// <summary> Retrieves the type of data stored in the wrapped Value instance </summary>
    /// <returns> The type </returns>
    ValueType GetType() const;

private:
    Value _value;
};

} // value
} // ell