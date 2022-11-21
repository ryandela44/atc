#include "ComputerSystem.h"

ComputerSystem::ComputerSystem(Radar radar, OperatorConsole console, Client client, Server server) : radar(radar), console(console), client(client), server(server){
client.init();
}

void ComputerSystem::compute_violation() {
for(auto aircraft : radar.getAircrafts()) {
	if (aircraft.get_x_coor() == x_constraint) {
	notify_airplane(aircraft.get_id());
	}

	if (aircraft.get_y_coor() == y_constraint) {
		notify_airplane(aircraft.get_id());
	}

	if (aircraft.get_z_coor() == z_constraint) {
	notify_airplane(aircraft.get_id());
	}
}
}

void ComputerSystem::alert() {

}

void ComputerSystem::send_to_display() {

}

void ComputerSystem::notify_airplane(uint64_t id) {
msg.hdr.type = 0x00;
msg.hdr.subtype = id;
client.send(msg);
}
