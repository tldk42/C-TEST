#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>

namespace lab7
{
	template <typename K, class V>
	std::map<K, V> ConvertVectorsToMap(const std::vector<K>& keys, const std::vector<V>& values)
	{
		std::map<K, V>        retMap;
		std::unordered_set<K> keySet;

		auto   key = keys.begin();
		auto   value = values.begin();
		size_t size = std::min(keys.size(), values.size());
		for (size_t i = 0; i < size; ++i)
		{
			if (!keySet.count(*key))
			{
				retMap.insert(std::pair<K, V>(*key, *(value++)));
				keySet.insert(*(key++));
			}
		}
		return retMap;
	}

	template <typename K, class V>
	std::vector<K> GetKeys(const std::map<K, V>& m)
	{
		std::vector<K> retVector;
		retVector.reserve(m.size());

		for (const auto& key : m)
		{
			retVector.push_back(key.first);
		}
		return retVector;
	}

	template <typename K, class V>
	std::vector<V> GetValues(const std::map<K, V>& m)
	{
		std::vector<V> retVector;
		retVector.reserve(m.size());

		for (const auto& value : m)
		{
			retVector.push_back(value.second);
		}
		return retVector;
	}

	template <typename T>
	std::vector<T> Reverse(const std::vector<T>& v)
	{
		std::vector<T> retVector;
		retVector.reserve(v.size());
		for (auto it = v.rbegin(); it != v.rend(); ++it)
		{
			retVector.push_back(*it);
		}
		return retVector;
	}

	template <typename T>
	std::vector<T> operator+(const std::vector<T>& v1, const std::vector<T>& v2)
	{
		std::vector<T> retValue;
		size_t         size = v1.size() + v2.size();
		retValue.reserve(size);
		std::unordered_set<T> unorderedSet;

		for (const auto& r : v1)
		{
			if (!unorderedSet.count(r))
			{
				retValue.push_back(r);
				unorderedSet.insert(r);
			}
		}
		for (const auto& l : v2)
		{
			if (!unorderedSet.count(l))
			{
				retValue.push_back(l);
				unorderedSet.insert(l);
			}
		}
		return retValue;
	}

	template <typename K, class V>
	std::map<K, V> operator+(const std::map<K, V>& m1, const std::map<K, V>& m2)
	{
		std::map<K, V>        combined;
		size_t                size = m1.size() + m2.size();
		std::unordered_set<K> unorderedSet;

		for (const auto& map : m1)
		{
			if (!unorderedSet.count(map.first))
			{
				combined.insert(map);
				unorderedSet.insert(map.first);
			}
		}
		for (const auto& map : m2)
		{
			if (!unorderedSet.count(map.first))
			{
				combined.insert(map);
				unorderedSet.insert(map.first);
			}
		}
		return combined;
	}

	template <typename T>
	std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
	{
		for (const auto& vector : v)
		{
			os << vector;
			if (vector == *(--v.end()))
				break;
			os << ", ";
		}
		return os;
	}

	template <typename K, class V>
	std::ostream& operator<<(std::ostream& os, const std::map<K, V>& m)
	{
		for (const auto& map : m)
		{
			os << "{ " << map.first << ", " << map.second << " }" << std::endl;
		}
		return os;
	}
}
