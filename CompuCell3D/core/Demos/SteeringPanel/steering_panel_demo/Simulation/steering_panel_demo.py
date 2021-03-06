from .steering_panel_demo_steppables import VolumeSteeringSteppable
from .steering_panel_demo_steppables import SurfaceSteeringSteppable
import cc3d.CompuCellSetup as CompuCellSetup

CompuCellSetup.register_steppable(steppable=VolumeSteeringSteppable(frequency=1))
CompuCellSetup.register_steppable(steppable=SurfaceSteeringSteppable(frequency=1))

CompuCellSetup.run()

