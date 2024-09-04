#pragma once

#include "./Layer.h"

namespace Baruah {

typedef std::vector<Layer*> LAYER_LIST;
	
class LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

		LAYER_LIST::iterator begin() { return m_Layers.begin(); }
		LAYER_LIST::iterator end() { return m_Layers.end(); }
	private:
		LAYER_LIST m_Layers;
		unsigned int m_LayerInsertIndex = 0;
	};
}

