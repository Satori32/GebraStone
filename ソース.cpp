#include <iostream>
#include <vector>
#include <cstdint>
#include <memory> 
#include <map>

class GebraStone {
public:
	struct GebraStonePoint;
	struct  GebraStonePointData;
	typedef std::shared_ptr<GebraStonePoint> SharedGebraStonePoint;
	typedef std::shared_ptr<GebraStonePointData> SharedGebraStonePointData;
	


	struct GebraStonePoint {
		struct GebraStonePointData {
			enum class Property : std::size_t {
				Zero = 0,
				One,
				Ninzin,
				Paseri,
			};

			typedef std::intmax_t DataType;// too better the rational lib.

			std::map<Property,DataType> Data;

			DataType& operator [](Property N) {
				return Data[N];
			}
			std::size_t Size() {
				return Data.size();
			}
		};

		std::vector<SharedGebraStonePoint> Oku;//maybe axis z.
		std::vector<SharedGebraStonePoint> Yoko;//maybe axis x.
		std::vector<GebraStonePointData> Data;
		std::vector<GebraStonePointData> Chash;

		bool NewOku() {
			Oku.push_back(std::make_shared<GebraStonePoint>());
			return true;
		}

		bool NewYoko() {
			Yoko.push_back(std::make_shared<GebraStonePoint>());
			return true;
		}


		GebraStonePointData& operator [](std::size_t N) {
				return Data[N];
		}
		std::size_t Size() {
			return Data.size();
		}
	};

	GebraStone::GebraStonePoint::GebraStonePointData& operator [](std::size_t In) {
		return Oku[0]->Data[In];
	}

	SharedGebraStonePoint& Get() {
		return Oku[0];
	}

	std::vector<SharedGebraStonePoint>& GetOku() {
		return this->Oku;
	}

	std::size_t OkuSize() {
		return this->Oku.size();
	}
	bool NewOku() {
			Oku.push_back(std::make_shared<GebraStonePoint>());
			return true;
	}
protected:
	std::vector<SharedGebraStonePoint> Oku;//maybe axis z.
};

int main() {
	GebraStone GS;

	GS.NewOku();
	GS.GetOku().push_back(std::make_shared<GebraStone::GebraStonePoint>());
	GS.GetOku()[0]->Data.push_back({});
	GS.GetOku()[0]->Data[0].Data.push_back(100);

	GS.GetOku()[0]->Data[0].Data[0]=50;

	return 0;
}