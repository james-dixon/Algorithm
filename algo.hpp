#ifndef ALGO_H
#define ALGO_H

#include <type_traits>
#include <cassert>

namespace algo
{

	namespace binary_search
	{
	
		template<class T, class Iterator>
		typename std::enable_if< std::is_same< std::random_access_iterator_tag,
											   typename std::iterator_traits<Iterator>::iterator_category >::value,
								 bool >::type
		exists(Iterator begin, Iterator end, const T& match)
		{
		
			while(begin!=end)
			{
				Iterator midpoint = begin + (end-begin)/2;
			
				if( *midpoint == match )
				{
					return true;
				}
				else if( *midpoint < match )
				{
					begin = midpoint+1;
				}
				else
				{
					end = midpoint;
				}
			}
			return false;
		
		}
	
	
		template<class T, class Iterator>
		typename std::enable_if< std::is_same< std::random_access_iterator_tag,
											   typename std::iterator_traits<Iterator>::iterator_category >::value,
								 Iterator >::type
		find(Iterator begin, Iterator end, const T& match)
		{
			const Iterator original_end = end;
			while(begin!=end)
			{
				Iterator midpoint = begin + (end-begin)/2;
			
				if( *midpoint == match )
				{
					return midpoint;
				}
				else if( *midpoint < match )
				{
					begin = midpoint+1;
				}
				else
				{
					end = midpoint;
				}
			}
			return original_end;
		
		}

		template<class T, class Iterator>
		typename std::enable_if< std::is_same< std::random_access_iterator_tag,
											   typename std::iterator_traits<Iterator>::iterator_category >::value,
								 Iterator >::type
		find_first(Iterator begin, Iterator end, const T& match)
		{
			const Iterator original_end = end;
		
			while(begin!=end)
			{
				Iterator midpoint = begin + (end-begin-1)/2;
				
				if( *begin == match )
				{
					return begin;
				}
				else if( *midpoint == match )
				{
					end = midpoint + 1;
				}
				else if( *midpoint < match )
				{
					begin = midpoint+1;
				}
				else
				{
					end = midpoint;
				}
				
			}
			return original_end;
		}

		
		template<class T, class Iterator>
		typename std::enable_if< std::is_same< std::random_access_iterator_tag,
											   typename std::iterator_traits<Iterator>::iterator_category >::value,
								 Iterator >::type
		find_last(Iterator begin, Iterator end, const T& match)
		{
			const Iterator original_end = end;
		
			while(begin!=end)
			{
				Iterator midpoint = begin + (end-begin)/2;

				if( *(end-1) == match )
				{
					return (end-1);
				}
				else if( *midpoint == match )
				{
					begin = midpoint;
				}
				else if( *midpoint < match )
				{
					begin = midpoint+1;
				}
				else
				{
					end = midpoint;
				}
			
			}
			return original_end;
		}
		
	}   
}


#endif


