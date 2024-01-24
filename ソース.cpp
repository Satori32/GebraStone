#include <iostream>
#include <vector>
#include <cstdint>
#include <memory> 
#include <map>
#include <string>

class GebraStone {
public:
	struct GebraStonePoint;
	struct  GebraStonePointData;
	typedef std::shared_ptr<GebraStonePoint> SharedGebraStonePoint;
	typedef std::shared_ptr<GebraStonePointData> SharedGebraStonePointData;
	typedef std::shared_ptr<std::vector<SharedGebraStonePoint>> SharedGebraStonePoints;


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

			bool HaveAProperty(Property P) {
				return Data.find(P)!=Data.end();
			}
		};
		struct Relation
		{
			struct Arrow
			{
				SharedGebraStonePoint To;
				std::intmax_t Weight = 0;
				std::vector<std::string> Origin;
				bool SetOrigin(const std::string& In) {
					Origin.push_back(In);
				}
				bool SetWeight(std::intmax_t In) {
					Weight = In;
				}

			};
			std::vector<Arrow> R;
			bool PushArrow(SharedGebraStonePoint P, std::intmax_t W) {
				R.push_back({ P,W ,{} });
				return true;
			}

			bool PopArrow(Arrow A) {
				for (auto i = R.begin(); i != R.end(); i++) {
					if (i->To == A.To) {
						R.erase(i);
						return true;
					}
				}
				return false;
			}

			std::vector<Arrow>::iterator begin() {
				return R.begin();
			}
			std::vector<Arrow>::iterator end() {
				return R.end();
			}
		};

		SharedGebraStonePoints Oku= std::make_shared<std::vector<SharedGebraStonePoint>>();//maybe axis z.
		SharedGebraStonePoints Yoko= std::make_shared<std::vector<SharedGebraStonePoint>>();//maybe axis x.
		std::vector<GebraStonePointData> Data;
		std::vector<GebraStonePointData> Chash;
		std::map<std::string, std::vector<SharedGebraStonePoint>> BookMark;
		Relation Arrows;

		Relation& GetRelation() {
			return Arrows;
		}

		bool NewOku() {
			Oku->push_back(std::make_shared<GebraStonePoint>());
			return true;
		}

		bool NewYoko() {
			Yoko->push_back(std::make_shared<GebraStonePoint>());
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
		return Oku->at(0)->Data[In];
	}

	SharedGebraStonePoints& Get() {
		return Oku;
	}

	SharedGebraStonePoints GetOku() {
		return (*this).Oku;
	}

	std::size_t OkuSize() {
		return this->Oku->size();
	}
	bool NewOku() {
			Oku->push_back(std::make_shared<GebraStonePoint>());
			return true;
	}
protected:
	SharedGebraStonePoints Oku=std::make_shared<std::vector<SharedGebraStonePoint>>();//maybe axis z.
};

int main() {
	GebraStone GS;

//	GS.NewOku();
	GS.GetOku()->push_back(std::make_shared<GebraStone::GebraStonePoint>());
	GS.GetOku()->at(0)->Data.push_back({});
	GS.GetOku()->at(0)->Data[0].Data[GebraStone::GebraStonePoint::GebraStonePointData::Property::Zero] = 100;

	GS.GetOku()->at(0)->Data[0].Data[GebraStone::GebraStonePoint::GebraStonePointData::Property::Zero] = 50;

	bool F = GS.GetOku()->at(0)->Data[0].HaveAProperty(GebraStone::GebraStonePoint::GebraStonePointData::Property::Zero);
	bool F2 = GS.GetOku()->at(0)->Data[0].HaveAProperty(GebraStone::GebraStonePoint::GebraStonePointData::Property::One);
	return 0;
}