#pragma once

// ������� ����� ��� ���� ��������� � ������
class Entity {

public:
	// ����������� ����������
	virtual ~Entity();
	// ����� ���������� ����� ������� delta ������ (��� ��������� ��������� ������ � ���������� ����� �� �������)
	virtual void tick(double delta);

};
