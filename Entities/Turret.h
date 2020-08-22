#ifndef _RTETURRET_
#define _RTETURRET_

#include "HeldDevice.h"

namespace RTE {

	class HeldDevice;

	/// <summary>
	/// A detatchable turret pod that can hold HeldDevices.
	/// </summary>
	class Turret : public Attachable {

	public:

		EntityAllocation(Turret)
		SerializableOverrideMethods
		ClassInfoGetters

#pragma region Creation
		/// <summary>
		/// Constructor method used to instantiate a Turret object in system memory. Create() should be called before using the object.
		/// </summary>
		Turret() { Clear(); }

		/// <summary>
		/// Creates a Turret to be identical to another, by deep copy.
		/// </summary>
		/// <param name="reference">A reference to the Turret to deep copy.</param>
		/// <returns>An error return value signaling sucess or any particular failure. Anything below 0 is an error signal.</returns>
		int Create(const Turret &reference);
#pragma endregion

#pragma region Destruction
		/// <summary>
		/// Destructor method used to clean up a Turret object before deletion from system memory.
		/// </summary>
		~Turret() override { Destroy(true); }

		/// <summary>
		/// Destroys and resets (through Clear()) the Turret object.
		/// </summary>
		/// <param name="notInherited">Whether to only destroy the members defined in this derived class, or to destroy all inherited members also.</param>
		void Destroy(bool notInherited = false) override { if (!notInherited) { Attachable::Destroy(); } Clear(); }

		/// <summary>
		/// Resets the entire Turret, including its inherited members, to their default settings or values.
		/// </summary>
		void Reset() override { Clear(); Attachable::Reset(); }
#pragma endregion

#pragma region Getters and Setters
		/// <summary>
		/// Indicates whether a HeldDevice is mounted or not.
		/// </summary>
		/// <returns>Whether or not a HeldDevice is mounted on this Turret.</returns>
		bool HasMountedDevice() const { return m_MountedDevice != nullptr; }

		/// <summary>
		/// Gets the mounted HeldDevice of this Turret.
		/// </summary>
		/// <returns>A pointer to mounted HeldDevice of this Turret. Ownership is NOT transferred!</returns>
		HeldDevice * GetMountedDevice() const { return m_MountedDevice; }

		/// <summary>
		/// Sets the mounted HeldDevice for this Turret. Ownership IS transferred!
		/// The currently mounted HeldDevice (if there is one) will be dropped and added to MovableMan.
		/// </summary>
		/// <param name="newMountedDevice">The new HeldDevice to use.</param>
		void SetMountedDevice(HeldDevice *newMountedDevice);

		/// <summary>
		/// Indicates whether a ThrownDevice is mounted or not.
		/// </summary>
		/// <returns>Whether or not a ThrownDevice is mounted on this Turret.</returns>
		bool IsThrownDeviceMounted() const { return m_MountedDevice && m_MountedDevice->IsThrownDevice(); }

		/// <summary>
		/// Sets the current rotational offset of the mounted HeldDevice from the rest of the Turret.
		/// </summary>
		/// <param name="newOffsetAngle">The new offset angle in radians, relative from the rest of the turret.</param>
		void SetMountedDeviceRotOffset(float newOffsetAngle) { m_MountedDeviceRotOffset = newOffsetAngle; }
#pragma endregion

#pragma region Mounted Device Management
		/// <summary>
		/// Makes this Turret unmount its mounted HeldDevice. Ownership IS transferred!
		/// </summary>
		/// <returns>A pointer to the previously mounted HeldDevice. Ownership IS transferred!</returns>
		HeldDevice * ReleaseMountedDevice();

		/// <summary>
		/// Makes this Turret unmount its mounted HeldDevice and give it to MovableMan. Ownership IS transferred to MovableMan.
		/// </summary>
		/// <returns>A pointer to the previously mounted HeldDevice. Ownership IS transferred to MovableMan.</returns>
		HeldDevice *DropMountedDevice();
#pragma endregion

#pragma region Override Methods
		/// <summary>
		/// Updates this MovableObject. Supposed to be done every frame.
		/// </summary>
		void Update() override;
#pragma endregion


		//These die soon
		float GetMass() const override;
		void SetID(const MOID newID) override;
		void GetMOIDs(std::vector<MOID> &MOIDs) const override;

	protected:

		//This dies soon
		void UpdateChildMOIDs(std::vector<MovableObject *> &MOIDIndex, MOID rootMOID = g_NoMOID, bool makeNewMOID = true) override;


		static Entity::ClassInfo m_sClass; //!< ClassInfo for this class.

		HeldDevice *m_MountedDevice; //<! Pointer to the mounted HeldDevice of this Turret, if any.
		float m_MountedDeviceRotOffset; //<! The relative offset angle (in radians) of the mounted HeldDevice from this Turret's rotation.

	private:

		/// <summary>
		/// Clears all the member variables of this Turret, effectively resetting the members of this abstraction level only.
		/// </summary>
		void Clear();

		// Disallow the use of some implicit methods.
		Turret(const Turret &reference) {}
		Turret &operator=(const Turret &rhs) {}
	};
}
#endif