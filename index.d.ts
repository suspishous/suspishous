declare module "suspishous" {
  export class AmongUs {
    jay3332(): never; // will throw the AmongUsError
    susAmount: number;
  }

  export class AmongUsError extends Error {
    sus: true;
  }
}
