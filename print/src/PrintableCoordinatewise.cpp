////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Project:  [projectName]
//  File:     PrintableCoordinatewise.cpp (print)
//  Authors:  Ofer Dekel
//
//  [copyright]
//
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "PrintableCoordinatewise.h"
#include "SvgHelpers.h"

std::string PrintableCoordinatewise::GetFriendlyLayerName() const
{
    return GetOperationName(GetOperationType());
}

uint64 PrintableCoordinatewise::Size() const
{
    return Coordinatewise::Size();
}

LayerLayout PrintableCoordinatewise::Print(std::ostream & os, double left, double top, uint64 layerIndex, const PrintArguments & Arguments) const
{
    auto layout = PrintableLayer::Print(os, left, top, layerIndex, GetFriendlyLayerName(), Size(), Arguments.valueElementLayout, Arguments.layerStyle);

   //// print the visible elements, before the dots
   for (uint64 k = 0; k < layout.NumVisibleElements()-1; ++k)
   {
        SvgValueElement(os, 2, layout.GetMidX(k), layout.GetMidY(), _values[k], Arguments.valueElementStyle.maxChars, k);
   }

   // print last element
   SvgValueElement(os, 2, layout.GetMidX(Size() - 1), layout.GetMidY(), _values[Size() - 1], Arguments.valueElementStyle.maxChars, Size() - 1);

   // if has hidden elements, draw the dots
   if(layout.HasHidden())
   {
       SvgDots(os, 2, layout.GetDotsMidX(), layout.GetMidY());
   }

   return layout;
}

layers::Layer::InputCoordinateIterator PrintableCoordinatewise::GetInputCoordinates(uint64 index) const
{
    return Coordinatewise::GetInputCoordinates(index);
}
