#include <iostream>
#include <vector>
#include <cstdint>
#include <memory> 

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

			std::vector<DataType> Data;

			DataType operator [](Property N) {
				return Data[(std::size_t)N];
			}
			std::size_t Size() {
				return Data.size();
			}
		};

		std::vector<SharedGebraStonePoint> Oku;//maybe axis z.
		std::vector<SharedGebraStonePoint> Yoko;//maybe axis x.
		std::vector<GebraStonePointData> Data;
		std::vector<GebraStonePointData> Chash;

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
protected:
	std::vector<SharedGebraStonePoint> Oku;//maybe axis z.
};

int main() {
	GebraStone GS;

	GS.Get()->Chash[0].Data[0] = 100;

	return 0;
}