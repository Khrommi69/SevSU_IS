#pragma once

// базовый класс для всех сущностей в модели
class Entity {

public:
	// виртуальный деструктор
	virtual ~Entity();
	// метод вызываемый через отрезок delta секунд (для изменения состояния модели с дискретным шагом по времени)
	virtual void tick(double delta);

};
